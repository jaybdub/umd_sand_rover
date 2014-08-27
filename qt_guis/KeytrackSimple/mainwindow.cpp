#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _marker_detector.setMinMaxSize(0.0001,0.5);

    ui->cameraResolutionComboBox->addItem("640x480");
    ui->cameraResolutionComboBox->addItem("1920x1080");

    _serial_port = new QSerialPort();
    refreshSerialPortOptions();
    connect(ui->serialConnectButton,SIGNAL(clicked()),SLOT(updateSerialPort()));
    connect(ui->serialDisconnectButton,SIGNAL(clicked()),SLOT(disconnectSerialPort()));
    connect(_serial_port,SIGNAL(readyRead()),SLOT(receiveData()));
    connect(ui->sendSerialDataButton,SIGNAL(clicked()),SLOT(sendTextEditSerialData()));
    connect(ui->sendSerialDataLineEdit,SIGNAL(returnPressed()),SLOT(sendTextEditSerialData()));
    connect(ui->refreshSerialOptionsButton,SIGNAL(clicked()),SLOT(refreshSerialPortOptions()));
    loadDefaultSettings();
    //applySettings();

    //Timer connects to the kcamera object to call grabFrame every 30 milliseconds
    _timer = new QTimer(this);
    connect(_timer,SIGNAL(timeout()),SLOT(update()));
    _timer->start(20);

    //Update video every 20ms
    QTimer* video_timer = new QTimer(this);
    connect(video_timer,SIGNAL(timeout()),SLOT(updateVideo()));
    video_timer->start(20);

    connect(ui->applySettingsButton,SIGNAL(clicked()),SLOT(applySettings()));

    QFileDialog* file_dialog = new QFileDialog();
    connect(file_dialog,SIGNAL(fileSelected(QString)),ui->calibrationFileLineEdit,SLOT(setText(QString)));
    connect(ui->browseCalibrationFileButton,SIGNAL(clicked()),file_dialog,SLOT(open()));

    //Connections for selecting view (image/2D trace)
    connect(ui->viewSelectComboBox,SIGNAL(currentIndexChanged(QString)),SLOT(selectView(QString)));

    connect(ui->saveSentDataButton,SIGNAL(clicked()),SLOT(saveSentData()));
    connect(ui->clearSentDataButton,SIGNAL(clicked()),SLOT(clearSentData()));

    ui->markerTracePlot->addGraph();
    ui->markerTracePlot->graph(0)->addData(1.5,1.5);

    ui->markerTracePlot->graph(0)->addData(1.9,1.9);
    ui->markerTracePlot->graph(0)->addData(1.5,1.9);
    ui->markerTracePlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCross);
    ui->markerTracePlot->replot();

    _running = false;
    _frame_count = 0;
    connect(ui->startRunButton,SIGNAL(clicked()),this,SLOT(startRun()));
    connect(ui->stopRunButton,SIGNAL(clicked()),this,SLOT(stopRun()));

    _received_data_max_length = 1000;
    _sent_data_max_length = 1000;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateVideo(){
    //Grab frame from camera
    if(_video_capture.isOpened()) {
        //_video_capture.
        //_video_capture >> _image;
        _video_capture.read(_image);
    }
}
void MainWindow::stopRun() {
    _running = false;
}

void MainWindow::startRun() {
    _frame_count = 0;
    _run_time.start();
    _running = true;
}

void MainWindow::updatePlotCoordinateFrame()
{

    ui->markerTracePlot->xAxis->setRange(0,_d_ox);
    ui->markerTracePlot->yAxis->setRange(0,_d_oy);
}

void MainWindow::selectView(QString name)
{
    if(name == QString("Video")) {
        ui->stackedWidget->setCurrentWidget(ui->Video);
    }
    else if (name == QString("Marker Trace"))
    {
        ui->stackedWidget->setCurrentWidget(ui->page_6);
    }
}

void MainWindow::loadDefaultSettings()
{
    //Camera device (0)
    ui->cameraDeviceSpinBox->setValue(0);
    //Resolution (640x480)
    ui->cameraResolutionComboBox->setCurrentText("640x480");
    //Frame interval (30ms)
    ui->frameIntLineEdit->setText("30");
    //Using calibration (false)
    ui->useCalibrationCheckBox->setChecked(false);
    //Marker size (0.1m)
    ui->markerSizeLineEdit->setText("0.1");
    //Dox (2m)
    ui->doxLineEdit->setText("2.0");
    ui->doyLineEdit->setText("1.0");
    QTextStream(stdout) << "Default settings loaded." << endl;

}

void MainWindow::loadSettings()
{

}

void MainWindow::saveSettings()
{

}

void MainWindow::applySettings()
{
    //Release the current device, and open
    //the new device.
    _camera_device = ui->cameraDeviceSpinBox->value();
    _video_capture.release();
    _video_capture.open(_camera_device);
    //_timer->stop;

    //Set the new resolution
    if(ui->cameraResolutionComboBox->currentText() == "640x480") {
        _camera_width = 640;
        _camera_height = 480;
        _video_capture.set(CV_CAP_PROP_FRAME_WIDTH, _camera_width);
        _video_capture.set(CV_CAP_PROP_FRAME_HEIGHT, _camera_height);
    }
    else if(ui->cameraResolutionComboBox->currentText() == "1920x1080"){

        _camera_width = 1920;
        _camera_height = 1080;
        _video_capture.set(CV_CAP_PROP_FRAME_WIDTH, _camera_width);
        _video_capture.set(CV_CAP_PROP_FRAME_HEIGHT, _camera_height);
    }
    _frame_interval_ms = ui->frameIntLineEdit->text().toInt();
    _timer->start(_frame_interval_ms);
    //Set using calibration
    _using_calibration = ui->useCalibrationCheckBox->isChecked();

    //Set marker size
    _marker_size = ui->markerSizeLineEdit->text().toFloat();

    //Set the arena size parameters
    _d_ox = ui->doxLineEdit->text().toFloat();
    _d_oy = ui->doyLineEdit->text().toFloat();

    //Load the calibration file from path specified
    try {
        _camera_parameters.readFromXMLFile(ui->calibrationFileLineEdit->text().toStdString());
        _camera_parameters.resize(cv::Size(_camera_width,_camera_height));
    }
    catch(cv::Exception e){

    }

    updatePlotCoordinateFrame();

    QTextStream(stdout) << "Settings applied." << endl;
}

void MainWindow::refreshSerialPortOptions()
{
    //Update selectable serial ports
    ui->availableSerialPortsComboBox->clear();
    QList<QSerialPortInfo> available_ports = QSerialPortInfo::availablePorts();
    for(int i = 0; i < available_ports.size(); i++){
        ui->availableSerialPortsComboBox->addItem(available_ports.at(i).portName());
    }

    //Update selectable baud rates
    ui->baudRateComboBox->clear();
    ui->baudRateComboBox->addItem(QString::number(QSerialPort::Baud1200));
    ui->baudRateComboBox->addItem(QString::number(QSerialPort::Baud2400));
    ui->baudRateComboBox->addItem(QString::number(QSerialPort::Baud4800));
    ui->baudRateComboBox->addItem(QString::number(QSerialPort::Baud9600));
    ui->baudRateComboBox->addItem(QString::number(QSerialPort::Baud19200));
    ui->baudRateComboBox->addItem(QString::number(QSerialPort::Baud38400));
    ui->baudRateComboBox->addItem(QString::number(QSerialPort::Baud57600));
    ui->baudRateComboBox->addItem(QString::number(QSerialPort::Baud115200));
}

void MainWindow::updateSerialPort()
{
    //Close the current serial port
    _serial_port->close();

    //Open new port for reading and writing
    QSerialPortInfo port_info(ui->availableSerialPortsComboBox->currentText());
    _serial_port->setPort(port_info);
    _serial_port->open(QIODevice::ReadWrite);
    if(_serial_port->isOpen())
    {
        //Set serial port options
        _serial_port->setBaudRate(ui->baudRateComboBox->currentText().toInt());
        _serial_port->setParity(QSerialPort::NoParity);
        _serial_port->setDataBits(QSerialPort::Data8);
        _serial_port->setStopBits(QSerialPort::OneStop);
        //Notify console
        QTextStream(stdout) << "Connected to serial port " << _serial_port->portName()
                            << " at baud rate " << QString::number(_serial_port->baudRate()) << endl;
    }
    else
    {
        QTextStream(stdout) << "Failed to connect" << endl;
    }
}

void MainWindow::disconnectSerialPort()
{
    if(_serial_port->isOpen())
        _serial_port->close();
}

void MainWindow::showImage(cv::Mat* image)
{
    QImage qimage = cvMatToQImage(*image);
    ui->image->setPixmap(QPixmap::fromImage(qimage.scaled(ui->image->size(),Qt::KeepAspectRatio)));
}
void MainWindow::receiveData()
{
    QByteArray data;
    data = _serial_port->readAll();
    _received_data.append(data);

    //Clip the received data (shown on GUI) to remain within max length
    if((_received_data.size() - _received_data_max_length) > 0)
        _received_data.remove(0,_received_data.size() - _received_data_max_length);

    //appendPlainText(QString(_serial_port->readAll()));
    ui->receivedDataTextEdit->setText(QString(_received_data));

    //Scroll to bottom
    QTextCursor c = ui->receivedDataTextEdit->textCursor();
    c.movePosition(QTextCursor::End);
    ui->receivedDataTextEdit->setTextCursor(c);
}

void MainWindow::sendData(QByteArray data)
{
    _serial_port->write(data);
    _sent_data.append(data);
    //Clip the sent data (shown on GUI) to remain within max length
    if((_sent_data.size() - _sent_data_max_length) > 0)
        _sent_data.remove(0,_sent_data.size() - _sent_data_max_length);

    ui->sentDataTextEdit->setText(_sent_data);

    //Scroll to bottom of sent data box
    QTextCursor c = ui->sentDataTextEdit->textCursor();
    c.movePosition(QTextCursor::End);
    ui->sentDataTextEdit->setTextCursor(c);
}
void MainWindow::sendTextEditSerialData()
{

    sendData(ui->sendSerialDataLineEdit->text().toUtf8().append('\n'));
    ui->sendSerialDataLineEdit->clear();
}

void MainWindow::update()
{
    if(_running) {
        //Update run time, if running
        int run_time_ms = _run_time.elapsed();
        // ui->runTimeLabel->setText(QString::number(run_time_ms));
        ui->runTimeLabel->setText(QTime(0,0).addMSecs(run_time_ms).toString("mm:ss.zzz"));
        ui->framesDetectedLabel->setText(QString::number(_frame_count));
    }
    if(_serial_port->isOpen()){
        ui->serialStatusLabel->setText("Status: connected");
    }
    else {
        ui->serialStatusLabel->setText("Status: disconnected");
    }
    //Grab frame from camera
    if(_video_capture.isOpened()) {
        //_video_capture.
        //_video_capture >> _image;
        //_video_capture.read(_image);
        long frame_time = _run_time.elapsed();
        _frame_count++;
        //Detect markers
        if(_using_calibration)
        {
            _marker_detector.detect(_image,_markers,_camera_parameters,_marker_size);
        }
        else
        {
            _marker_detector.detect(_image,_markers);
        }
        //Iterate through all detected markers
        //Set timestamp
        for(int i=0;i < _markers.size();i++) {
            _markers[i].draw(_image,cv::Scalar(0,0,255),2);
            //Update origin, x-axis, and y-axis coordinates if the marker corresponds to one of those
            if(_markers[i].id == 0) {
                _origin[0] = _markers[i].Tvec.ptr<float>(0)[0];
                _origin[1] = _markers[i].Tvec.ptr<float>(0)[1];
                _origin[2] = _markers[i].Tvec.ptr<float>(0)[2];
                _origin_px[0] = _markers[i][0].x;
                _origin_px[1] = _markers[i][0].y;
            }
            else if(_markers[i].id == 1) {
                _x_axis[0] = _markers[i].Tvec.ptr<float>(0)[0];
                _x_axis[1] = _markers[i].Tvec.ptr<float>(0)[1];
                _x_axis[2] = _markers[i].Tvec.ptr<float>(0)[2];
                _x_axis_px[0] = _markers[i][0].x;
                _x_axis_px[1] = _markers[i][0].y;
            }
            else if(_markers[i].id == 2) {
                _y_axis[0] = _markers[i].Tvec.ptr<float>(0)[0];
                _y_axis[1] = _markers[i].Tvec.ptr<float>(0)[1];
                _y_axis[2] = _markers[i].Tvec.ptr<float>(0)[2];
                _y_axis_px[0] = _markers[i][0].x;
                _y_axis_px[1] = _markers[i][0].y;
            }
            else {
                //Convert marker to keytrack marker by calculating X, Y, and Theta
                KeytrackMarker kmarker = arucoMarkerToKeytrackMarker(_markers[i]);
                //QTextStream(stdout) << _y_axis[0] << endl;
               /* QTextStream(stdout) << "ID: " << QString::number(kmarker.id) <<
                                       "X: " << QString::number(kmarker.x) <<
                                       "Y: " << QString::number(kmarker.y) << endl;*/
                if(_serial_port->isOpen()){
                    //Send marker over serial
                    QString line;
                    line.append(QString::number(kmarker.id));
                    line.append(',');
                    line.append(QString::number(kmarker.x,'g',3));
                    line.append(',');
                    line.append(QString::number(kmarker.y,'g',3));
                    line.append(',');
                    line.append(QString::number(kmarker.theta,'g',3));
                    line.append(',');
                    line.append(QString::number(frame_time));
                    line.append('\n');
                    sendData(line.toUtf8());
                }
                //Add marker point to trajectory
                //_marker_trajectories.addMarker(kmarker);
                //KeytrackMarkerTrajectory trajectory = _marker_trajectories.getTrajectory(kmarker.id);
                //ui->sentDataTextEdit->setText(QString::number(trajectory.size()));
            }
            //QTextStream(stdout) << "Marker " << QString::number(i) << endl;
            //Draw markers on image
        }

        //Show frame from camera
        showImage(&_image);
    }
}

KeytrackMarker MainWindow::arucoMarkerToKeytrackMarker(aruco::Marker marker)
{
    KeytrackMarker kmarker;
    float marker_position[3];
    marker_position[0] = marker.Tvec.ptr<float>(0)[0];
    marker_position[1] = marker.Tvec.ptr<float>(0)[1];
    marker_position[2] = marker.Tvec.ptr<float>(0)[2];

    //current markers.
    float ox[3];
    float oy[3];
    float om[3];
    //Compute the vector from the the origin marker to the x_axis marker.
    //ox = keytrack::diff(_x_axis,_origin);
    for(int i=0;i<3;i++){
        ox[i] = _x_axis[i] - _origin[i];
    }
    //ox = keytrack::normalize(ox); //(axis vectors are normalized)
    float ox_mag = sqrt(ox[0]*ox[0]+ox[1]*ox[1]+ox[2]*ox[2]);
    for(int i=0;i<3;i++){
        ox[i] = ox[i]/ox_mag;
    }
    // " y_axis marker.
    //oy = keytrack::diff(_y_axis,_origin);
    for(int i=0;i<3;i++){
        oy[i] = _y_axis[i] - _origin[i];
    }
    //oy = keytrack::normalize(oy);
    float oy_mag = sqrt(oy[0]*oy[0]+oy[1]*oy[1]+oy[2]*oy[2]);
    for(int i=0;i<3;i++){
        oy[i] = oy[i]/oy_mag;
    }

    // " current marker.
    //om = keytrack::diff(marker_position,_origin);
    for(int i=0;i<3;i++){
        om[i] = marker_position[i] - _origin[i];
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
    kmarker.x = om[0]*ox[0]+om[1]*ox[1]+om[2]*ox[2];
    kmarker.x = kmarker.x*_d_ox/ox_mag;
    //kmarker.y = keytrack::dot(om,oy);
    kmarker.y = om[0]*oy[0]+om[1]*oy[1]+om[2]*oy[2];
    kmarker.y = kmarker.y*_d_oy/oy_mag;
    //Set the keytrack marker id
    kmarker.id = marker.id;

    //calculate theta using pixel locations
    float dm_px[2];
    dm_px[0] = marker[1].x - marker[0].x;
    dm_px[1] = marker[1].y - marker[0].y;

    float ox_px[2], oy_px[2];
    //Calculate vector from origin to x-axis marker in pixels
    ox_px[0] = _x_axis_px[0] - _origin_px[0];
    ox_px[1] = _x_axis_px[1] - _origin_px[1];

    //Normalize the vector
    float ox_px_mag = sqrt(ox_px[0]*ox_px[0]+ox_px[1]*ox_px[1]);
    ox_px[0] = ox_px[0] / ox_px_mag;
    ox_px[1] = ox_px[1] / ox_px_mag;

    //Calculate vector from origin to y-axis marker in pixels
    oy_px[0] = _y_axis_px[0] - _origin_px[0];
    oy_px[1] = _y_axis_px[1] - _origin_px[1];

    //Normalize the vector
    float oy_px_mag = sqrt(oy_px[0]*oy_px[0]+oy_px[1]*oy_px[1]);
    oy_px[0] = oy_px[0] / oy_px_mag;
    oy_px[1] = oy_px[1] / oy_px_mag;

    //Calculate the projection of dm_px onto the x-axis
    float proj_dm_ox_px, proj_dm_oy_px;
    proj_dm_ox_px = dm_px[0]*ox_px[0]+dm_px[1]*ox_px[1];
    proj_dm_oy_px = dm_px[0]*oy_px[0]+dm_px[1]*oy_px[1];

    kmarker.theta = atan2(proj_dm_oy_px,proj_dm_ox_px);
    return kmarker;
}

void MainWindow::clearSentData()
{
    _sent_data.clear();
    ui->sentDataTextEdit->clear();
}
void MainWindow::saveSentData()
{
    QTextStream(stdout) << "Saving sent data.";
}

void MainWindow::clearReceivedData()
{
    _received_data.clear();
    ui->receivedDataTextEdit->clear();
}
void MainWindow::saveReceivedData()
{

    QTextStream(stdout) << "Saving received data.";
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
