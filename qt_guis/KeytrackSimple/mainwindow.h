#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <aruco/aruco.h>
#include "qcustomplot.h"
#include <QTextStream>
#include "keytrackmarkertrajectory.h"
#include "keytrackmarkertrajectorylist.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>
#include <QFileDialog>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void showImage(cv::Mat* image);
    void updatePlotCoordinateFrame();
    QImage cvMatToQImage( const cv::Mat &inMat );
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void loadSettings();
    void saveSettings();
    void applySettings();
    void receiveData();
    void sendData(QByteArray data);
    void update();
    void loadDefaultSettings();
    void refreshSerialPortOptions();
    void updateSerialPort();
    void disconnectSerialPort();
    void sendTextEditSerialData();
    void selectView(QString name);
    void clearSentData();
    void saveSentData();
    void clearReceivedData();
    void saveReceivedData();
private:
    KeytrackMarker arucoMarkerToKeytrackMarker(aruco::Marker marker);
    int _camera_device;
    int _camera_width;
    int _camera_height;
    bool _using_calibration;
    float _marker_size;
    float _d_ox;
    float _d_oy;
    float _origin[3];
    float _x_axis[3];
    float _y_axis[3];
    float _origin_px[2];
    float _x_axis_px[2];
    float _y_axis_px[2];
    //QCustomPlot* marker_trace;
    KeytrackMarkerTrajectoryList _marker_trajectories;
    QSerialPort* _serial_port;
    QByteArray _received_data;
    QByteArray _sent_data;
    aruco::MarkerDetector _marker_detector;
    vector<aruco::Marker> _markers;
    cv::VideoCapture _video_capture;
    aruco::CameraParameters _camera_parameters;
    cv::Mat _image;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
