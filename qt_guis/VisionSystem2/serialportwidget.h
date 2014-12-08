/*  File:
 *
 *      serialportwidget.h
 *
 *  Authors:
 *
 *      John Welsh
 *
 *  Brief:
 *
 *      Defines the widget which is used to connect, configure,
 *      and visualize a serial port.
 *
 *  Usage:
 *
 *      int writeData(QByteArray data)
 *
 *          Slot that sends data over the serial port, updating the
 *          widget's sent data text box.
 *
 *      int dataReceived(QByteArray data)
 *
 *          Signal that is generated when any data is received
 *          over the serial port.
*/

#ifndef SERIALPORTWIDGET_H
#define SERIALPORTWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QtSerialPort/QtSerialPort>
#include <QMenu>
#include <QPlainTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QByteArray>
#include <QComboBox>
#include <QScrollBar>
#include <QCheckBox>
#include "marker.h"
#include <QLineEdit>

class SerialPortWidget : public QFrame
{
    Q_OBJECT
public:
    explicit SerialPortWidget(QString portName, QWidget *parent = 0);
    ~SerialPortWidget();
    QString getPortName();
signals:
    void dataReceived(QByteArray data);
    void dataSent(QByteArray data);
public slots:
    int writeData(QByteArray data);
    void handleNewMarkers(QList<Marker> markers);
private slots:
    void readData();
    void updateCommunicationStatsLabel();
    void setBaudRate(QString baudRate);
    void refreshConnectionStatus();
private:
    void handleNewChar(char c);
    void resetState();
    QList<int> parseRequestString(QString rs);
    QVBoxLayout *mainVBoxLayout;
    QHBoxLayout *layout;
    QPushButton *configButton;
    QPushButton *communicationButton;
    QLabel *serialPortNameLabel;
    QSerialPort *serialPort;
    QWidget *configWidget;
    QWidget *communicationWidget;
    QPlainTextEdit *sentDataTextEdit;
    QPlainTextEdit *receivedDataTextEdit;
    QString portName;
    int bytesSent; //Total # of bytes sent.
    int bytesRead;
    QComboBox *baudRateComboBox;
    QCheckBox *receivedAutoscrollCheckbox;
    QCheckBox *sentAutoscrollCheckbox;
    QLabel *communicationStatsLabel;
    QTimer *refreshConnectionStatusTimer;
    QLabel *connectedIconLabel;
    QList<int> markerRequestIds;
    int state;
    QString requestString;
    QString messageString;
    QLineEdit *messageLineEdit;

};

#endif // SERIALPORTWIDGET_H
