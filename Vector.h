#ifndef VECTOR_H
#define VECTOR_H

class Vector{
public:
    Vector();
    Vector(float x, float y, float z);
    float x;
    float y;
    float z;
    Vector operator +(Vector);
    Vector operator -(Vector);
    Vector operator *(int);
};

#endif