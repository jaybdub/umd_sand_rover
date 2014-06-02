#include "keytrackmarkertrajectory.h"

KeytrackMarkerTrajectory::KeytrackMarkerTrajectory(int id, int max_size, double distance_between_points)
{
    _id = id;
    _max_size = max_size;
    _distance_between_points = distance_between_points;
}


void KeytrackMarkerTrajectory::addPoint(double x, double y)
{
    //If radius is positive, then check to make sure the point to be added
    //is far enough away from the last point before adding
    if(true)
    {
        //If we're too large, remove the oldest point from the trajectory.
        if(_points.size() > _max_size) {
            _points.erase(_points.begin());
        }
        //Add the new point to the trajectory
        KeytrackPoint p;
        p.x = x;
        p.y = y;
        _points.push_back(p);
    }
}

std::vector<double> KeytrackMarkerTrajectory::getX()
{
    std::vector<double> x;
    for(int i=0;i<_points.size();i++)
    {
        x.push_back(_points.at(i).x);
    }
    return x;
}

std::vector<double> KeytrackMarkerTrajectory::getY()
{
    std::vector<double> y;
    for(int i=0;i<_points.size();i++)
    {
        y.push_back(_points.at(i).y);
    }
    return y;
}

int KeytrackMarkerTrajectory::getId()
{
    return _id;
}

int KeytrackMarkerTrajectory::size()
{
    return _points.size();
}
