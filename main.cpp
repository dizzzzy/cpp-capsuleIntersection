#include <iostream> 
#include "Point.h"
#include "Vector.h"
#include "Segment.h"
#include "Capsule.h"
#include "math.h"
//#include <glm/glm.hpp>
using namespace std;
//using namespace glm;

#define PI 3.14159265

int main(){
    Vector v1(1.0,0.0,0.0);
    Vector v2(4.0, 3.0, 3.0);
    Point p1(5.0, 1.0, 1.0);
    Point p2(3.0, 0.0, 0.0);
    Point p3;
    Vector v3;
    //test point operators
    v3 = p1 - p2; 
    p3 = p1 + v1;
    p2 = p3 - v1;
    //test vector operators
    v3 = v1 + v2;
    v3 = v3- v2;
    v3 = v1 * 3;
    Point p4(2.0, 2.0, 0.0);
    Point p5(2.0, 2.0, 1.0);
    Segment s1(p4,p5);
    Point p6(1.0, 1.0, 0.0);
    Point p7(0.0, 2.0, 0.0);
    Segment s2(p6, p7);
    //Testing Segment to Segment distance
    float distance = Segment::dist3D_Segment_to_Segment(s1, s2);
    Capsule c1(0.7, p4, p5);
    Capsule c2(0.705, p6, p7);
    //Testing Capsule to Capsule intersection
    bool intersect = Capsule::intersect(c1,c2);

    //opengl testing  capsule
    Point a(-21.24, 4.0, -19.74);
    Point b(-10.756, 4.0, -15.26);
    Segment s3(a,b);
    Capsule cap3(1.42, a, b);
    Point c(-11.24, 4.0, -16.267);
    Point d(-10.756, 4.0, -19.73);
    Segment s4(c,d);
    Capsule cap4(1.42, c, d);
    intersect = Capsule::intersect(cap3,cap4);
    distance = Segment::dist3D_Segment_to_Segment(s4,s3);

    bool bottom;
    bool top;
    bool left;
    bool right;
    bool inverseX;
    bool inverseZ;
    bool collided;
    //check Boundary Walls
     if( (cap3.segment->P0.z + cap3.radius > 20) || (cap3.segment->P1.z + cap3.radius > 20) ){
        bottom = true;
        collided = true;
        inverseZ = true;
    }else{
        bottom = false;
        inverseZ = false;
    }
    if( (cap3.segment->P0.z - cap3.radius < -20) || cap3.segment->P1.z - cap3.radius < -20){
        top = true;
        collided = true;
        inverseZ = true;
    }else{
        top = false;
        inverseZ = false;
    }
    if( (cap3.segment->P0.x + cap3.radius > 20) || (cap3.segment->P1.x + cap3.radius > 20)){
        right = true;
        collided = true;
        inverseX = true;
    }else{
        right = false;
        inverseX = false;
    }
    if( (cap3.segment->P0.x - cap3.radius < -20) || (cap3.segment->P1.x - cap3.radius < -20)){
        left = true;
        collided = true;
        inverseX = true;
    }else{
        left = false;
        inverseX = false;
    }
    // glm::vec4 point1;
    // point1.x =  cap3.segment->P0.x;
    // point1.r = cap3.segment->P0.y;
    // point1.s = cap3.segment->P0.z;
    // glm::vec4 point2(cap3.segment->P1.x, cap3.segment->P1.y, cap3.segment->P1.z, 1);
    // glm::vec4 direction = point2 - point1;
    // direction.y = 0;
    // Vector direction = cap3.segment->P1 - cap3.segment->P0; 
    // direction.y =0;
    //direction = glm::normalize(direction);
    Vector direction = a-b; 

    float param, result;
    float bonus = 0;
    if(direction.z >= 0 && direction.x >= 0){
        bonus = 0; //first quadrant
    }else if(direction.z >=0 && direction.x<=0 ){
        bonus = 180.0; //second quadrant
    }else if(direction.z <=0 && direction.x<=0){
        bonus = 180.0; //third quadrant
    }else{
        bonus = 0; //fourth quadrant
    }
    param = (direction.z/direction.x);
    result = atan(param) * 180 / PI + bonus;
    if(result <0){
        result = 360 + result;
    }
    
    printf ("The incident direction angle is of %f degrees\n", result );

    if(inverseX){
        direction.x = -direction.x;
    }
    if(inverseZ){
        direction.z = -direction.z;
    }

    if(direction.z >= 0 && direction.x >= 0){
        bonus = 0; //first quadrant
    }else if(direction.z >=0 && direction.x<=0 ){
        bonus = 180.0; //second quadrant
    }else if(direction.z <=0 && direction.x<=0){
        bonus = 180.0; //third quadrant
    }else{
        bonus = 0; //fourth quadrant
    }
    param = (direction.z/direction.x); //this will be the normalized vector.y/vector.x
    result = atan (param) * 180 / PI;
    if(result <0){
        result = 360 + result; //this will be what we will put as orientation 
    }
    printf ("The reflected direction angle is of %f degrees\n", result );

    

    //transform normalized vector to degrees
    
   cout<< "Is this Capsule out of bounds? " << collided << endl;
    




    getchar();
    return 0;
}

