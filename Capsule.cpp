#include "Capsule.h"

Capsule::Capsule(float radius, Point p1, Point p2 ){
    this->radius = radius;
    this->segment = new Segment(p1, p2);
}

bool Capsule::intersect(Capsule c1, Capsule c2){
    if(c1.radius + c2.radius > Segment::dist3D_Segment_to_Segment(*c1.segment, *c2.segment)){
        return true; 
    } else{
        return false;
    }
}