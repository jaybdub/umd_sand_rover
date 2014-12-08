#include "serialportwidget.h"

SerialPortWidget::SerialPortWidget(QString portName, QWidget *parent) :
    QFrame(parent)
{
    this->portName = portName;

    //Initialize the serial port. (default)
    serialPort = new QSerialPort(portName,this);
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    connect(serialPort,SIGNAL(readyRead()),this,SLOT(readData()));
    serialPort->open(QSerialPort::ReadWrite);

    //Initialize the connected icon
    connectedIconLabel = new QLabel(this);
    connectedIconLabel->setPixmap(QIcon(":/icons/connected").pixmap(10,10));
    connectedIconLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    if(!serialPort->isOpen())
        connectedIconLabel->hide();
    refreshConnectionStatusTimer = new QTimer(this);
    connect(refreshConnectionStatusTimer,SIGNAL(timeout()),this,SLOT(refreshConnectionStatus()));
    refreshConnectionStatusTimer->start(1000); //Check every second.

    //Initialize the serial port label;
    serialPortNameLabel = new QLabel(this);
    serialPortNameLabel->setText(portName);
    serialPortNameLabel->setFont(QFont("Courier New",12));

    //Initialize transmission stats label
    bytesSent = 0;
    bytesRead = 0;
    communicationStatsLabel = new QLabel(QString("(")+QString::number(bytesSent)+QString(" : ")+QString::number(bytesRead)
                                         +QString(" : ")+QString::number(markerRequestIds.length())+QString(")"));
    communicationStatsLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    communicationStatsLabel->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);

    //Requests label
//    requestsLabel = new QLabel("(r: 0)");
//    communicationStatsLabel->setAlignment(Qt::AlignRight | Qt::AlignCenter);
//    communicationStatsLabel->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);

    //Initialize the baud rate combo box.
    QComboBox *baudRateComboBox = new QComboBox(this);
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud1200));
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud2400));
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud4800));
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud9600));
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud19200));
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud38400));
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud57600));
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud115200));
    baudRateComboBox->setCurrentText(QString::number(QSerialPort::Baud9600));
    baudRateComboBox->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    connect(baudRateComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(setBaudRate(QString)));

    //Initialize the communication button.
    communicationButton = new QPushButton(this);
    communicationButton->setIcon(QIcon(":/icons/communication"));
    communicationButton->resize(30,30);
    communicationButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //Message line edit
    messageLineEdit = new QLineEdit(this);

    //Set up the widget's primary layout.
    mainVBoxLayout = new QVBoxLayout(this);
    layout = new QHBoxLayout(this);
    mainVBoxLayout->addLayout(layout);
    mainVBoxLayout->addWidget(messageLineEdit);
    layout->addWidget(connectedIconLabel);
    layout->addWidget(serialPortNameLabel);
    layout->addWidget(communicationStatsLabel);
    layout->addWidget(baudRateComboBox);
    layout->addWidget(communicationButton);

    //Apply layout to widget, set constraints, and frame style.
    this->setLayout(mainVBoxLayout);
    this->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    this->setFrameShape(QFrame::Panel);
    this->setFrameShadow(QFrame::Raised);
    this->setLineWidth(2);

    //Initialize the communication widget.
    communicationWidget = new QWidget(this);
    communicationWidget->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint |
                                        Qt::WindowTitleHint | Qt::WindowSystemMenuHint |
                                        Qt::WindowCloseButtonHint);//Make the config a pop-up window
    communicationWidget->setWindowTitle(portName+QString(" data"));
    communicationWidget->setWindowIcon(QIcon(":/icons/communication"));
    connect(communicationButton,SIGNAL(clicked()),communicationWidget,SLOT(show()));

    //Initialize features of the communication layout.
    QIcon *sentDataIcon = new QIcon(":/icons/sent");
    QLabel *sentDataIconLabel = new QLabel(communicationWidget);
    sentDataIconLabel->setPixmap(sentDataIcon->pixmap(16,16));
    sentDataIconLabel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    QLabel *sentDataLabel = new QLabel("Sent",communicationWidget);
    sentDataLabel->setFont(QFont("Courier New"));
    sentDataLabel->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);

    sentDataTextEdit = new QPlainTextEdit(communicationWidget);
    sentDataTextEdit->setReadOnly(true);

    sentAutoscrollCheckbox = new QCheckBox("autoscroll", communicationWidget);
    sentAutoscrollCheckbox->setChecked(true);
    sentAutoscrollCheckbox->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    QIcon *receivedDataIcon = new QIcon(":/icons/received");
    QLabel *receivedDataIconLabel = new QLabel(communicationWidget);
    receivedDataIconLabel->setPixmap(receivedDataIcon->pixmap(16,16));
    receivedDataIconLabel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    QLabel *receivedDataLabel = new QLabel("Received",communicationWidget);
    receivedDataLabel->setFont(QFont("Courier New"));
    receivedDataLabel->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);

    receivedDataTextEdit = new QPlainTextEdit(communicationWidget);
    receivedDataTextEdit->setReadOnly(true);

    receivedAutoscrollCheckbox = new QCheckBox("autoscroll", communicationWidget);
    receivedAutoscrollCheckbox->setChecked(true);
    receivedAutoscrollCheckbox->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    //Initialize the communication layout.
    QVBoxLayout *communicationLayout = new QVBoxLayout(communicationWidget);

    QHBoxLayout *sentBarLayout = new QHBoxLayout;
    sentBarLayout->addWidget(sentDataIconLabel);
    sentBarLayout->addWidget(sentDataLabel);
    sentBarLayout->addWidget(sentAutoscrollCheckbox);

    QHBoxLayout *receivedBarLayout = new QHBoxLayout;
    receivedBarLayout->addWidget(receivedDataIconLabel);
    receivedBarLayout->addWidget(receivedDataLabel);
    receivedBarLayout->addWidget(receivedAutoscrollCheckbox);

    communicationLayout->addLayout(sentBarLayout);
    communicationLayout->addWidget(sentDataTextEdit);
    communicationLayout->addLayout(receivedBarLayout);
    communicationLayout->addWidget(receivedDataTextEdit);
}
SerialPortWidget::~SerialPortWidget()
{
    serialPort->close();
}
void SerialPortWidget::resetState()
{
    this->state = 0;
}

void SerialPortWidget::handleNewChar(char c)
{
    switch(state){
    case 0:
        if(c=='#'){
            state = 1;
            requestString = QString("");
        }
        else if (c=='@'){
            state = 2;
            messageString = QString("");
        }
        break;
    case 1:
        if(c=='*'){
            //Determine requested marker ids.
            QList<int> requestedMarkerIds = parseRequestString(this->requestString);

            for(int i=0;i<requestedMarkerIds.size();i++){
                this->markerRequestIds.removeAll(requestedMarkerIds.at(i));
                this->markerRequestIds.append(requestedMarkerIds.at(i));
            }
            qDebug() << serialPort->portName() + QString("marker request: ") + this->requestString;
            //Reset state to 0 (waiting)
            state = 0;
        }
        else if (c=='~'){
            this->resetState();
        }
        else {
            //Add character to request string.
            requestString.append(c);
        }
        break;
    case 2:
        if(c=='*'){
            //Determine requested marker ids.
            qDebug() << serialPort->portName() + QString(" message: ") + messageString;
            this->messageLineEdit->setText(messageString);
            //Reset state to 0 (waiting)
            state = 0;
        }
        else if (c=='~'){
            this->resetState();
        }
        else {
            //Add character to request string.
            messageString.append(c);
        }
        break;
    default:
        state = 0;
    }
}
QList<int> SerialPortWidget::parseRequestString(QString rs)
{
    QList<int> markerIds;

    //Split string at comma (',') into a list of marker strings
    QStringList markerStrings = rs.split(",",QString::SkipEmptyParts);

    for(int i=0;i<markerStrings.size();i++) {

        //Convert each markerString to an integer and add it to
        //the list of ids.
        markerIds.append(markerStrings.at(i).toInt());
    }

    return markerIds;
}

void SerialPortWidget::handleNewMarkers(QList<Marker> markers)
{
    QList<int> newMarkerIds;
    for(int i=0;i<markers.length();i++){
        //Check if marker was requested
        if(this->markerRequestIds.contains(markers.at(i).id)){
            //Send marker
            QString markerString = QString("");
            markerString += QString::number(markers.at(i).id);
            markerString += QString(",") + QString::number(markers.at(i).pose.x);
            markerString += QString(",") + QString::number(markers.at(i).pose.y);
            markerString += QString(",") + QString::number(markers.at(i).pose.theta);
            markerString += QString(",") + QString::number(0);//markers.at(i).time.msec());
            markerString += QString('\n');
            qDebug() << this->serialPort->portName() + QString(": ") + markerString;
            this->writeData(markerString.toUtf8());
        }
        newMarkerIds.append(markers.at(i).id);
    }
    //remove markers from queue
    QMutableListIterator<int> it(this->markerRequestIds);
    while (it.hasNext()) {
        if (newMarkerIds.contains(it.next()))
            it.remove();
    }
}

void SerialPortWidget::readData()
{
    QByteArray data = serialPort->readAll();

    //Place received data in text edit.
    receivedDataTextEdit->insertPlainText(QString(data));

    //Scroll to bottom if autoscrolling is enabled
    if(receivedAutoscrollCheckbox->isChecked())
        receivedDataTextEdit->verticalScrollBar()->setValue(receivedDataTextEdit->verticalScrollBar()->maximum());

    bytesRead += data.size();
    updateCommunicationStatsLabel();

    for(int i =0;i<data.length();i++)
        this->handleNewChar(data.at(i));

    //Fire dataReceived signal.
    emit dataReceived(data);
}
int SerialPortWidget::writeData(QByteArray data)
{
    //Place sent data in text edit.
    sentDataTextEdit->insertPlainText(QString(data));

    //Scroll to bottom if autoscrolling is enabled.
    if(sentAutoscrollCheckbox->isChecked())
        sentDataTextEdit->verticalScrollBar()->setValue(sentDataTextEdit->verticalScrollBar()->maximum());

    bytesSent += data.size();
    updateCommunicationStatsLabel();

    return serialPort->write(data);
}

QString SerialPortWidget::getPortName()
{
    return portName;
}

void SerialPortWidget::updateCommunicationStatsLabel()
{
    this->communicationStatsLabel->setText(QString("(")+QString::number(bytesSent)+QString(" : ")
                                           +QString::number(bytesRead)+QString(" : ")+QString::number(markerRequestIds.length())+QString(")"));
}
void SerialPortWidget::setBaudRate(QString baudRate)
{
    serialPort->setBaudRate(baudRate.toInt());
}
void SerialPortWidget::refreshConnectionStatus()
{
    //If not open, hide the connected icon and attempt to open.
    if(!serialPort->isOpen()){
        connectedIconLabel->hide();
        serialPort->open(QSerialPort::ReadWrite);
    }
    else
        connectedIconLabel->show();

}
