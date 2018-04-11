#include "Point.h"


Point::Point(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point::Point(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector Point::operator -(Point p1){
    float vecX;
    float vecY;
    float vecZ;
    vecX = this->x - p1.x;
    vecY = this->y - p1.y;
    vecZ = this->z - p1.z;
    Vector vec(vecX, vecY, vecZ);
    return vec; 
}

Point Point::operator +(Vector vec1){
     float pX; 
     float pY;
     float pZ;
     pX = this->x + vec1.x;
     pY = this->y + vec1.y;
     pZ = this->z + vec1.z;
     Point p(pX, pY, pZ);
     return p;
 }

Point Point::operator -(Vector vec1){
    float pX; 
    float pY;
    float pZ;
    pX = this->x - vec1.x;
    pY = this->y - vec1.y;
    pZ = this->z - vec1.z;
    Point p(pX, pY, pZ);
    return p;
}

