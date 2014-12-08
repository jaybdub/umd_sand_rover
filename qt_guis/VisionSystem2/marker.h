#ifndef MARKER_H
#define MARKER_H

#include <QTime>
#include "pose.h"

class Marker
{
public:
    Marker(int id);
    Marker(int id, QTime time);
    Marker(int id, Pose pose);
    Marker(int id, Pose pose, QTime time);
    QString toQString();
    int id;
    Pose pose;
    QTime time;
};

#endif // MARKER_H
