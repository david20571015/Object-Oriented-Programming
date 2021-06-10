#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include "trans.cpp"

int tex[3][2] = {{0, 0}, {50796070, 54422086}, {COLOR(255, 255, 150), COLOR(255, 255, 150)}};

class Cube
{
private:
    int x, y, z;
    Point vertex[8];

public:
    int texture;
    Cube();
    Cube(Point, int);
    void show(Camera &c, int **h);
};

Cube::Cube()
{
    for (int i = 0; i < 8; i++)
    {
        vertex[i].x = 0;
        vertex[i].y = 0;
        vertex[i].z = 0;
    }
    texture = -1;
}
Cube::Cube(Point p, int tex)
{
    x = p.x / 128;
    y = p.y / 128;
    z = p.z / 128;
    texture = tex;
    for (int i = 0; i < 8; i++)
        vertex[i] = p;

    vertex[1].z += 128;

    vertex[2].x += 128;
    vertex[2].z += 128;

    vertex[3].x += 128;

    vertex[4].y += 128;

    vertex[5].y += 128;
    vertex[5].z += 128;

    vertex[6].x += 128;
    vertex[6].y += 128;
    vertex[6].z += 128;

    vertex[7].x += 128;
    vertex[7].y += 128;
}

void Cube::show(Camera &c, int **h)
{
    int ps[8];
    Point t[8];
    setcolor(0);

    for (int i = 0; i < 8; i++)
    {
        t[i] = trans(vertex[i], c);
        if (t[i].y < -4 * window_w || t[i].y > 4 * window_w || t[i].z < -4 * window_h || t[i].z > 4 * window_h)
            return;
    }

    if (c.p.y < vertex[0].y && h[x][y - 1] < z + 1)
    {
        ps[0] = t[0].y;
        ps[1] = t[0].z;
        ps[2] = t[1].y;
        ps[3] = t[1].z;
        ps[4] = t[2].y;
        ps[5] = t[2].z;
        ps[6] = t[3].y;
        ps[7] = t[3].z;

        setfillstyle(1, tex[texture][0]);
        fillpoly(4, ps);
    }

    if (c.p.x > vertex[2].x && h[x + 1][y] < z + 1)
    {
        ps[0] = t[2].y;
        ps[1] = t[2].z;
        ps[2] = t[3].y;
        ps[3] = t[3].z;
        ps[4] = t[7].y;
        ps[5] = t[7].z;
        ps[6] = t[6].y;
        ps[7] = t[6].z;

        setfillstyle(1, tex[texture][0]);
        fillpoly(4, ps);
    }

    if (c.p.y > vertex[4].y && h[x][y + 1] < z + 1)
    {
        ps[0] = t[6].y;
        ps[1] = t[6].z;
        ps[2] = t[7].y;
        ps[3] = t[7].z;
        ps[4] = t[4].y;
        ps[5] = t[4].z;
        ps[6] = t[5].y;
        ps[7] = t[5].z;

        setfillstyle(1, tex[texture][0]);
        fillpoly(4, ps);
    }

    if (c.p.x < vertex[0].x && h[x - 1][y] < z + 1)
    {
        ps[0] = t[0].y;
        ps[1] = t[0].z;
        ps[2] = t[1].y;
        ps[3] = t[1].z;
        ps[4] = t[5].y;
        ps[5] = t[5].z;
        ps[6] = t[4].y;
        ps[7] = t[4].z;

        setfillstyle(1, tex[texture][0]);
        fillpoly(4, ps);
    }

    if (c.p.z > vertex[2].z && (h[x][y] == z + 1 || h[x][y] == z))
    {
        ps[0] = t[1].y;
        ps[1] = t[1].z;
        ps[2] = t[2].y;
        ps[3] = t[2].z;
        ps[4] = t[6].y;
        ps[5] = t[6].z;
        ps[6] = t[5].y;
        ps[7] = t[5].z;

        setfillstyle(1, tex[texture][1]);
        fillpoly(4, ps);
    }
}