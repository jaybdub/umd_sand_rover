#include "keytrackmarkertrajectorylist.h"

KeytrackMarkerTrajectoryList::KeytrackMarkerTrajectoryList()
{
}

void KeytrackMarkerTrajectoryList::addMarker(KeytrackMarker marker)
{
    //Check if marker id exists in trajectories
    for(int i=0;i<_marker_trajectories.size();i++) {
        //If a trajectory for the given marker id already exists, add the marker to the trajectory and exit.
        if(_marker_trajectories.at(i).getId() == marker.id) {
            _marker_trajectories.at(i).addPoint(marker.x,marker.y);
            return;
        }
    }
    //Marker trajectory does not exist, create a new one.
    KeytrackMarkerTrajectory new_trajectory(marker.id);
    new_trajectory.addPoint(marker.x,marker.y);
    _marker_trajectories.push_back(new_trajectory);
}

KeytrackMarkerTrajectory KeytrackMarkerTrajectoryList::getTrajectory(int id)
{
    for(int i=0;i<_marker_trajectories.size();i++)
    {
        if(_marker_trajectories.at(i).getId() == id)
        {
            return _marker_trajectories.at(i);
        }
    }
    return KeytrackMarkerTrajectory(-1);
}
