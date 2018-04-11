#include "Vector.h"

Vector::Vector(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector::Vector(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector Vector::operator +(Vector vec1){
    float vX;
    float vY;
    float vZ;
    vX = this->x + vec1.x;
    vY = this->y + vec1.y;
    vZ = this->z + vec1.z;
    Vector vec(vX, vY, vZ);
    return vec;
}

Vector Vector::operator -(Vector vec1){
    float vX;
    float vY;
    float vZ;
    vX = this->x - vec1.x;
    vY = this->y - vec1.y;
    vZ = this->z - vec1.z;
    Vector vec(vX, vY, vZ);
    return vec;
}

Vector Vector::operator *(int scalar){
    float vX;
    float vY;
    float vZ;
    vX = this->x * scalar;
    vY = this->y * scalar;
    vZ = this->z * scalar;
    Vector vec(vX, vY, vZ);
    return vec;
}