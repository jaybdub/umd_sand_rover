#include "serialmonitor.h"
#include "ui_serialmonitor.h"

SerialMonitor::SerialMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialMonitor)
{
    ui->setupUi(this);
}

SerialMonitor::~SerialMonitor()
{
    delete ui;
}
