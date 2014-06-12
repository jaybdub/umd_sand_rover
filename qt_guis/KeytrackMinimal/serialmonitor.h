#ifndef SERIALMONITOR_H
#define SERIALMONITOR_H

#include <QWidget>

namespace Ui {
class SerialMonitor;
}

class SerialMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit SerialMonitor(QWidget *parent = 0);
    ~SerialMonitor();

private:
    Ui::SerialMonitor *ui;
};

#endif // SERIALMONITOR_H
