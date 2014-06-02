#ifndef KEYTRACKMARKERTRAJECTORYLIST_H
#define KEYTRACKMARKERTRAJECTORYLIST_H
#include <vector>
#include "keytrackmarkertrajectory.h"

class KeytrackMarkerTrajectoryList
{
public:
    KeytrackMarkerTrajectoryList();
    void addMarker(KeytrackMarker marker);
    KeytrackMarkerTrajectory getTrajectory(int id);
private:
    std::vector<KeytrackMarkerTrajectory> _marker_trajectories;
};

#endif // KEYTRACKMARKERTRAJECTORYLIST_H
