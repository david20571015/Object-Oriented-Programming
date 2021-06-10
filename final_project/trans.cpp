#include <math.h>

#define window_h 1000
#define window_w 1600
#define D 1000 //distance between camera and screen

struct Point
{
    double x, y, z;
};

struct Camera
{
    Point p;
    double phi, theta;
};

Point trans(Point &model, Camera &c)
{
    Point t = model;
    t.x -= c.p.x;
    t.y -= c.p.y;
    t.z -= c.p.z;
    Point tt = t;
    double angle[4] = {sin(c.phi), cos(c.phi), sin(c.theta), cos(c.theta)};
    tt.x = t.x * angle[3] * angle[1] + t.y * angle[3] * angle[0] + t.z * angle[2];
    tt.y = -t.x * angle[0] + t.y * angle[1];
    tt.z = -t.x * angle[2] * angle[1] - t.y * angle[2] * angle[0] + t.z * angle[3];
    tt.y = -D * tt.y / tt.x + window_w / 2;
    tt.z = -D * tt.z / tt.x + window_h / 2;
    return tt;
}