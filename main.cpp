#include <iostream> 
#include "Point.h"
#include "Vector.h"
#include "Segment.h"
#include "Capsule.h"
using namespace std;

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
    Point a(-11.24, 4.0, -21.74);
    Point b(-10.756, 4.0, -18.26);
    Segment s3(a,b);
    Capsule cap3(1.42, a, b);
    Point c(-11.24, 4.0, -16.267);
    Point d(-10.756, 4.0, -19.73);
    Segment s4(c,d);
    Capsule cap4(1.42, c, d);
    intersect = Capsule::intersect(cap3,cap4);
    distance = Segment::dist3D_Segment_to_Segment(s4,s3);
    getchar();
    return 0;
}