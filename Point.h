#ifndef POINT_H
#define POINT_H
#include "Vector.h"

class Point{
public:
    Point();
    Point(float x, float y, float z);
    float x;
    float y;
    float z;
    Vector operator -(Point);
    Point operator +(Vector);
    Point operator -(Vector);
};

#endif