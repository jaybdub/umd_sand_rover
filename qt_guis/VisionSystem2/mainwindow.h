#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialportlistwidget.h"
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <aruco/aruco.h>
#include "marker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void applySettings();
    void fillDefaultSettings();
    void update();
    void updateBrightness(int brightness);
    void updateSharpness(int sharpness);
    void updateAutoFocus(bool auto_focus);
    void updateFocus(int focus);
private:

    Ui::MainWindow *ui;
    //Utility functions
    QImage cvMatToQImage(const cv::Mat &inMat);
    Marker arucoMarkerToMarker(aruco::Marker marker);

    //Objects
    SerialPortListWidget *splw;
    cv::VideoCapture videoCapture;
    QTimer *frameRateTimer;
    aruco::MarkerDetector markerDetector;
    aruco::CameraParameters cameraParameters;
    cv::Mat image;
    QImage qimage;
    vector<aruco::Marker> markers;
    QList<Marker> kmarkers;
    float origin[3];
    float xAxis[3];
    float yAxis[3];
    float originPx[2];
    float xAxisPx[2];
    float yAxisPx[2];

    //Settings
    uint cameraDevice;
    QSize cameraResolution;
    uint frameRate;
    float markerSize;
    float arenaWidth;
    float arenaHeight;
    QString calibrationFile;
//    uint cameraBrightness;
//    uint cameraSharpness;
//    uint cameraFocus;
};

#endif // MAINWINDOW_H
