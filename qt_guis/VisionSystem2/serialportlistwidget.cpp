#include "serialportlistwidget.h"

SerialPortListWidget::SerialPortListWidget(QWidget *parent) :
    QWidget(parent)
{
    refreshPortsTimer = new QTimer(this);
    connect(refreshPortsTimer,SIGNAL(timeout()),this,SLOT(refreshPorts()));
    refreshPortsTimer->start(500); //Check twice a second.

    //Initialize the vertical layout.
    mainLayout = new QVBoxLayout(this);
    spacer = new QWidget(this);
    spacer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
}

void SerialPortListWidget::handleNewMarkers(QList<Marker> markers)
{
    for(int i=0;i<this->serialPortWidgets.length();i++)
    {
        serialPortWidgets.at(i)->handleNewMarkers(markers);
    }
}

void SerialPortListWidget::refreshPorts()
{

    //Grab a list of available serial ports.
    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

    //Check to see if any of the current serialPortWidgets aren't in the list of available ports.  If so, destroy and remove hem.
    for(int i=0; i < serialPortWidgets.length(); i++){
        bool isAvailable = false;
        for(int j=0; j < availablePorts.length(); j++){
            if(availablePorts.at(j).portName() == serialPortWidgets.at(i)->getPortName())
                isAvailable = true;
        }

        //Remove the serial port widget from the list
        if(!isAvailable) {
            mainLayout->removeWidget(serialPortWidgets.at(i));
            delete serialPortWidgets.at(i);
            serialPortWidgets.removeAt(i);
        }
    }

    //Check to see if any available serial ports aren't on the list. If so, add them to the QList,
    //and add them to the mainLayout.
    for(int i=0; i < availablePorts.length(); i++){
        bool isListed = false;

        //Check if the port is listed.
        for(int j=0; j < serialPortWidgets.length(); j++){
            if(availablePorts.at(i).portName() == serialPortWidgets.at(j)->getPortName())
                isListed = true;
        }

        //If the port is not already listed, add it.
        if(!isListed) {
            serialPortWidgets.append(new SerialPortWidget(availablePorts.at(i).portName(),this));
            mainLayout->addWidget(serialPortWidgets.last());
        }
    }
    //Redo spacing on layout.
    try {
        mainLayout->removeWidget(spacer);
        mainLayout->addWidget(spacer);
    }
    catch (int e) {}

}
