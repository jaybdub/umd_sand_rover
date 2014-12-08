#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    splw = new SerialPortListWidget(this);
    ui->communicationVBoxLayout->addWidget(splw);

    //Connect browse button
    QFileDialog* fileDialog = new QFileDialog();
    connect(fileDialog,SIGNAL(fileSelected(QString)),ui->calibrationFileLineEdit,SLOT(setText(QString)));
    connect(ui->calibrationFilePushButton,SIGNAL(clicked()),fileDialog,SLOT(open()));

    //Connect apply settings button
    connect(ui->applySettingsPushButton,SIGNAL(clicked()),this,SLOT(applySettings()));

    //Frame rate timer
    frameRateTimer = new QTimer(this);
    fillDefaultSettings();
    connect(frameRateTimer,SIGNAL(timeout()),this,SLOT(update()));

    //Initialize marker detector
    markerDetector.setMinMaxSize(0.0001,0.5);

    //Camera view
    updateAutoFocus(false);
    updateFocus(ui->cameraFocusSlider->value());
    updateBrightness(ui->cameraBrightnessSlider->value());
    updateSharpness(ui->cameraSharpnessSlider->value());
    connect(ui->cameraFocusSlider,SIGNAL(valueChanged(int)),this,SLOT(updateFocus(int)));
    connect(ui->cameraBrightnessSlider,SIGNAL(valueChanged(int)),this,SLOT(updateBrightness(int)));
    connect(ui->cameraSharpnessSlider,SIGNAL(valueChanged(int)),this,SLOT(updateSharpness(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update()
{
    if(videoCapture.isOpened()) {
       //Grab image
       videoCapture.read(image);
       markerDetector.detect(image,markers,cameraParameters,markerSize);
       kmarkers.clear();
       for(int i=0;i < markers.size();i++) {
           markers[i].draw(image,cv::Scalar(0,0,255),2);
           //Update coordinate markers if applicalbe, otherwise calculate marker pose
           if(markers[i].id == 0) {
               origin[0] = markers[i].Tvec.ptr<float>(0)[0];
               origin[1] = markers[i].Tvec.ptr<float>(0)[1];
               origin[2] = markers[i].Tvec.ptr<float>(0)[2];
               originPx[0] = markers[i][0].x;
               originPx[1] = markers[i][0].y;
           }
           else if(markers[i].id == 1) {
               xAxis[0] = markers[i].Tvec.ptr<float>(0)[0];
               xAxis[1] = markers[i].Tvec.ptr<float>(0)[1];
               xAxis[2] = markers[i].Tvec.ptr<float>(0)[2];
               xAxisPx[0] = markers[i][0].x;
               xAxisPx[1] = markers[i][0].y;
           }
           else if(markers[i].id == 2) {
               yAxis[0] = markers[i].Tvec.ptr<float>(0)[0];
               yAxis[1] = markers[i].Tvec.ptr<float>(0)[1];
               yAxis[2] = markers[i].Tvec.ptr<float>(0)[2];
               yAxisPx[0] = markers[i][0].x;
               yAxisPx[1] = markers[i][0].y;
           }
           else {
               //Convert marker to keytrack marker by calculating X, Y, and Theta
               Marker kmarker = arucoMarkerToMarker(markers[i]);
               kmarkers.append(kmarker);
           }
       }
       //Fulfill any marker requests
       splw->handleNewMarkers(kmarkers);

       //Display augmented image
       qimage = cvMatToQImage(image);
       ui->imageLabel->setPixmap(QPixmap::fromImage(qimage.scaled(ui->imageLabel->size(),Qt::KeepAspectRatio)));
    }
}
Marker MainWindow::arucoMarkerToMarker(aruco::Marker marker)
{
    Marker kmarker(marker.id);
    float marker_position[3];
    marker_position[0] = marker.Tvec.ptr<float>(0)[0];
    marker_position[1] = marker.Tvec.ptr<float>(0)[1];
    marker_position[2] = marker.Tvec.ptr<float>(0)[2];

    //current markers.
    float ox[3];
    float oy[3];
    float om[3];
    //Compute the vector from the the origin marker to the x_axis marker.
    //ox = keytrack::diff(xAxis,origin);
    for(int i=0;i<3;i++){
        ox[i] = xAxis[i] - origin[i];
    }
    //ox = keytrack::normalize(ox); //(axis vectors are normalized)
    float ox_mag = sqrt(ox[0]*ox[0]+ox[1]*ox[1]+ox[2]*ox[2]);
    for(int i=0;i<3;i++){
        ox[i] = ox[i]/ox_mag;
    }
    // " y_axis marker.
    //oy = keytrack::diff(yAxis,origin);
    for(int i=0;i<3;i++){
        oy[i] = yAxis[i] - origin[i];
    }
    //oy = keytrack::normalize(oy);
    float oy_mag = sqrt(oy[0]*oy[0]+oy[1]*oy[1]+oy[2]*oy[2]);
    for(int i=0;i<3;i++){
        oy[i] = oy[i]/oy_mag;
    }

    // " current marker.
    //om = keytrack::diff(marker_position,origin);
    for(int i=0;i<3;i++){
        om[i] = marker_position[i] - origin[i];
    }

    //normalize current marker
    /*float om_mag = sqrt(om[0]*om[0]+om[1]*om[1]+om[2]*om[2]);
    for(int i=0;i<3;i++){
        om[i] = om[i]/om_mag;
    }*/

    //Calculate position of the current marker along the x axis.  This is the projection
    //of the vector from the origin to the current marker onto the normalized vector that defines the
    //x axis.
    //kmarker.x = keytrack::dot(om,ox);
    kmarker.pose.x = om[0]*ox[0]+om[1]*ox[1]+om[2]*ox[2];
    kmarker.pose.x = kmarker.pose.x*arenaWidth/ox_mag;
    //kmarker.y = keytrack::dot(om,oy);
    kmarker.pose.y = om[0]*oy[0]+om[1]*oy[1]+om[2]*oy[2];
    kmarker.pose.y = kmarker.pose.y*arenaHeight/oy_mag;
    //Set the keytrack marker id
    kmarker.id = marker.id;

    //calculate theta using pixel locations
    float dmPx[2];
    dmPx[0] = marker[1].x - marker[0].x;
    dmPx[1] = marker[1].y - marker[0].y;

    float oxPx[2], oyPx[2];
    //Calculate vector from origin to x-axis marker in pixels
    oxPx[0] = xAxisPx[0] - originPx[0];
    oxPx[1] = xAxisPx[1] - originPx[1];

    //Normalize the vector
    float oxPx_mag = sqrt(oxPx[0]*oxPx[0]+oxPx[1]*oxPx[1]);
    oxPx[0] = oxPx[0] / oxPx_mag;
    oxPx[1] = oxPx[1] / oxPx_mag;

    //Calculate vector from origin to y-axis marker in pixels
    oyPx[0] = yAxisPx[0] - originPx[0];
    oyPx[1] = yAxisPx[1] - originPx[1];

    //Normalize the vector
    float oyPx_mag = sqrt(oyPx[0]*oyPx[0]+oyPx[1]*oyPx[1]);
    oyPx[0] = oyPx[0] / oyPx_mag;
    oyPx[1] = oyPx[1] / oyPx_mag;

    //Calculate the projection of dmPx onto the x-axis
    float proj_dm_oxPx, proj_dm_oyPx;
    proj_dm_oxPx = dmPx[0]*oxPx[0]+dmPx[1]*oxPx[1];
    proj_dm_oyPx = dmPx[0]*oyPx[0]+dmPx[1]*oyPx[1];

    kmarker.pose.theta = atan2(proj_dm_oyPx,proj_dm_oxPx);
    return kmarker;
}
void MainWindow::fillDefaultSettings()
{
    ui->cameraDeviceSpinBox->setValue(0);
    ui->cameraResolutionComboBox->setCurrentText("1920x1080");
    ui->frameRateLineEdit->setText("25");
    ui->markerSizeLineEdit->setText("0.1");
    ui->arenaWidthLineEdit->setText("4.0");
    ui->arenaHeightLineEdit->setText("2.0");
    ui->cameraBrightnessSlider->setValue(50);
    ui->cameraSharpnessSlider->setValue(150);
    ui->calibrationFileLineEdit->setText("/home/admin/umd_sand_rover/data/logitech_C920_1_calibration.yaml");
    ui->cameraFocusSlider->setValue(0);
}

void MainWindow::applySettings()
{
    qDebug() << QString("== SETTINGS APPLIED ==");
    //Set camera device and reconnect camera.
    cameraDevice = ui->cameraDeviceSpinBox->value();
    videoCapture.release();
    videoCapture.open(cameraDevice);
    qDebug() << QString("Camera Device: ") + QString::number(cameraDevice);

    //Set camera resolution
    QStringList resString = ui->cameraResolutionComboBox->currentText().split("x",QString::SkipEmptyParts);
    cameraResolution = QSize(resString.at(0).toInt(),resString.at(1).toInt());
    videoCapture.set(CV_CAP_PROP_FRAME_WIDTH, cameraResolution.width());
    videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, cameraResolution.height());
    qDebug() << QString("Camera Resolution: ") + QString::number(cameraResolution.width())+QString("x")+QString::number(cameraResolution.height());

    //Frame rate
    frameRate = ui->frameRateLineEdit->text().toInt();
    frameRateTimer->start(frameRate);
    qDebug() << QString("Frame Rate: ") + QString::number(frameRate);

    //Set marker size
    markerSize = ui->markerSizeLineEdit->text().toFloat();
    qDebug() << QString("Marker Size: ") + QString::number(markerSize);

    //Set the arena size parameters
    arenaWidth = ui->arenaWidthLineEdit->text().toFloat();
    arenaHeight = ui->arenaHeightLineEdit->text().toFloat();
    qDebug() << QString("Arena Width: ") + QString::number(arenaWidth);
    qDebug() << QString("Arena Height: ") + QString::number(arenaHeight);

    //Load the calibration file from path specified
    try {
        cameraParameters.readFromXMLFile(ui->calibrationFileLineEdit->text().toStdString());
        cameraParameters.resize(cv::Size(cameraResolution.width(),cameraResolution.height()));
    }
    catch(cv::Exception e){

    }
    qDebug() << QString("Calibration File: ") + ui->calibrationFileLineEdit->text();
    qDebug() << QString("Camera Brightness: ") + QString::number(ui->cameraBrightnessSlider->value());
    qDebug() << QString("Camera Sharpness: ") + QString::number(ui->cameraSharpnessSlider->value());
    qDebug() << QString("Camera Focus: ") + QString::number(ui->cameraFocusSlider->value());
}
inline QImage MainWindow::cvMatToQImage( const cv::Mat &inMat )
   {
      switch ( inMat.type() )
      {
         // 8-bit, 4 channel
         case CV_8UC4:
         {
            QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB32 );

            return image;
         }

         // 8-bit, 3 channel
         case CV_8UC3:
         {
            QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888 );

            return image.rgbSwapped();
         }

         // 8-bit, 1 channel
         case CV_8UC1:
         {
            static QVector<QRgb>  sColorTable;

            // only create our color table once
            if ( sColorTable.isEmpty() )
            {
               for ( int i = 0; i < 256; ++i )
                  sColorTable.push_back( qRgb( i, i, i ) );
            }

            QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8 );

            image.setColorTable( sColorTable );

            return image;
         }

         default:
            //qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
            break;
      }

      return QImage();
   }

void MainWindow::updateAutoFocus(bool auto_focus) {
    QString command;
    command = command + QString("v4l2-ctl -d /dev/video");
    command = command + QString::number(cameraDevice);
    command = command + QString(" -c focus_auto=");
    if(ui->autofocusCheckbox->isChecked())
        command = command + QString("1");
    else {
        command = command + QString("0");
        this->updateFocus(ui->cameraFocusSlider->value());
    }

    system(command.toStdString().c_str());
    ui->tempLabel->setText(command);
    QTextStream(stdout) << command;
}
void MainWindow::updateFocus(int focus) {
    QString command;
    command = command + QString("v4l2-ctl -d /dev/video");
    command = command + QString::number(cameraDevice);
    command = command + QString(" -c focus_absolute=");
    command = command + QString::number(focus);

    system(command.toStdString().c_str());
}

void MainWindow::updateSharpness(int sharpness) {
    QString command;
    command = command + QString("v4l2-ctl -d /dev/video");
    command = command + QString::number(cameraDevice);
    command = command + QString(" -c sharpness=");
    command = command + QString::number(sharpness);

    system(command.toStdString().c_str());
}

void MainWindow::updateBrightness(int brightness) {
    QString command;
    command = command + QString("v4l2-ctl -d /dev/video");
    command = command + QString::number(cameraDevice);
    command = command + QString(" -c brightness=");
    command = command + QString::number(brightness);

    system(command.toStdString().c_str());
}
