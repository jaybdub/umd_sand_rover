#include "pose.h"
Pose::Pose()
{
    this->x = 0.0f;
    this->y = 0.0f;
    this->theta = 0.0f;
}

Pose::Pose(float x, float y, float theta)
{
    this->x = x;
    this->y = y;
    this->theta = theta;
}
