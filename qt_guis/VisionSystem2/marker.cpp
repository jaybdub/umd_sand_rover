#include "marker.h"

Marker::Marker(int id)
{
    this->id = id;
}

Marker::Marker(int id, QTime time)
{
    this->id = id;
    this->time = time;
}

Marker::Marker(int id, Pose pose)
{
    this->id = id;
    this->pose = pose;
}

Marker::Marker(int id, Pose pose, QTime time)
{
    this->id = id;
    this->pose = pose;
    this->time = time;
}

QString Marker::toQString()
{
    return QString::number(this->id)+QString(",")+QString::number(this->pose.x)+QString(",")+QString::number(this->pose.y)+QString(",")+QString::number(this->pose.theta);
}
