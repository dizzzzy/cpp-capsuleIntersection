#ifndef CAPSULE_H
#define CAPSULE_H
#include "Segment.h"

class Capsule{
public:
    Capsule(float, Point, Point);
    Segment* segment;
    float radius;
    bool static intersect(Capsule, Capsule);
};

#endif