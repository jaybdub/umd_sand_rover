#ifndef KEYTRACKMARKERTRAJECTORY_H
#define KEYTRACKMARKERTRAJECTORY_H

#include <vector>
#include <math.h>

struct KeytrackMarker {
    int id;
    float x;
    float y;
    float theta;
};

struct KeytrackPoint {
    double x;
    double y;
};

class KeytrackMarkerTrajectory
{
public:
    KeytrackMarkerTrajectory(int id, int max_size = 300, double distance_between_points = -1);
    void addPoint(double x, double y);
    std::vector<double> getX();
    std::vector<double> getY();
    int getId();
    int size();
private:
    int _id;
    int _max_size;
    int _distance_between_points;
    std::vector<KeytrackPoint> _points;

};

#endif // KEYTRACKMARKERTRAJECTORY_H
