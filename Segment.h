#ifndef SEGMENT_H
#define SEGMENT_H
#include "Point.h"

class Segment{
public:
    Segment(Point, Point);
    static float dist3D_Segment_to_Segment(Segment, Segment);
    Point P0;
    Point P1;
};

#endif