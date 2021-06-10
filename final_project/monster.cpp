#include <time.h>
#include <stdlib.h>
#include <math.h>

class Monster
{
    Point vertex[8];

public:
    Point p;
    Monster();
    bool alive;
    bool visible;
    void explode(Camera &c);
    void create_monster(Camera &c, World &w);
    void move(Camera &c, World &w);
    void show(Camera &c);
    void vis(Camera &c, World &w);
};

Monster::Monster()
{
}

void Monster::create_monster(Camera &c, World &w)
{
    p.x = c.p.x + cos(2 * ((double)rand() / RAND_MAX) * 3.14159) * 128;
    p.y = c.p.y + sin(2 * ((double)rand() / RAND_MAX) * 3.14159) * 128;
    p.z = w.h[(int)(p.x / 128)][(int)(p.y / 128)] * 128 + 64;
}

void Monster::move(Camera &c, World &w)
{
    p.x += (c.p.x - p.x) / 100;
    p.y += (c.p.y - p.y) / 100;
    p.z = w.h[(int)(p.x / 128)][(int)(p.y / 128)] * 128 + 64;
    vertex[0].x = p.x - 32;
    vertex[0].y = p.y - 32;
    vertex[0].z = p.z - 32;

    vertex[1].x = p.x - 32;
    vertex[1].y = p.y - 32;
    vertex[1].z = p.z + 32;

    vertex[2].x = p.x + 32;
    vertex[2].y = p.y - 32;
    vertex[2].z = p.z + 32;

    vertex[3].x = p.x + 32;
    vertex[3].y = p.y - 32;
    vertex[3].z = p.z - 32;

    vertex[4].x = p.x - 32;
    vertex[4].y = p.y + 32;
    vertex[4].z = p.z - 32;

    vertex[5].x = p.x - 32;
    vertex[5].y = p.y + 32;
    vertex[5].z = p.z + 32;

    vertex[6].x = p.x + 32;
    vertex[6].y = p.y + 32;
    vertex[6].z = p.z + 32;

    vertex[7].x = p.x + 32;
    vertex[7].y = p.y + 32;
    vertex[7].z = p.z - 32;
}

void Monster::show(Camera &c)
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

    if (c.p.y < vertex[0].y)
    {
        ps[0] = t[0].y;
        ps[1] = t[0].z;
        ps[2] = t[1].y;
        ps[3] = t[1].z;
        ps[4] = t[2].y;
        ps[5] = t[2].z;
        ps[6] = t[3].y;
        ps[7] = t[3].z;

        setfillstyle(1, 58489980);
        fillpoly(4, ps);
    }

    if (c.p.x > vertex[2].x)
    {
        ps[0] = t[2].y;
        ps[1] = t[2].z;
        ps[2] = t[3].y;
        ps[3] = t[3].z;
        ps[4] = t[7].y;
        ps[5] = t[7].z;
        ps[6] = t[6].y;
        ps[7] = t[6].z;

        setfillstyle(1, 58489980);
        fillpoly(4, ps);
    }

    if (c.p.y > vertex[4].y)
    {
        ps[0] = t[6].y;
        ps[1] = t[6].z;
        ps[2] = t[7].y;
        ps[3] = t[7].z;
        ps[4] = t[4].y;
        ps[5] = t[4].z;
        ps[6] = t[5].y;
        ps[7] = t[5].z;

        setfillstyle(1, 58489980);
        fillpoly(4, ps);
    }

    if (c.p.x < vertex[0].x)
    {
        ps[0] = t[0].y;
        ps[1] = t[0].z;
        ps[2] = t[1].y;
        ps[3] = t[1].z;
        ps[4] = t[5].y;
        ps[5] = t[5].z;
        ps[6] = t[4].y;
        ps[7] = t[4].z;

        setfillstyle(1, 58489980);
        fillpoly(4, ps);
    }

    if (c.p.z > vertex[2].z)
    {
        ps[0] = t[1].y;
        ps[1] = t[1].z;
        ps[2] = t[2].y;
        ps[3] = t[2].z;
        ps[4] = t[6].y;
        ps[5] = t[6].z;
        ps[6] = t[5].y;
        ps[7] = t[5].z;

        setfillstyle(1, 58489980);
        fillpoly(4, ps);
    }

    if (c.p.z < vertex[2].z)
    {
        ps[0] = t[0].y;
        ps[1] = t[0].z;
        ps[2] = t[4].y;
        ps[3] = t[4].z;
        ps[4] = t[7].y;
        ps[5] = t[7].z;
        ps[6] = t[3].y;
        ps[7] = t[3].z;

        setfillstyle(1, 58489980);
        fillpoly(4, ps);
    }
}

void Monster::vis(Camera &c, World &w)
{
    double dist = sqrt((p.x - c.p.x) * (p.x - c.p.x) + (p.y - c.p.y) * (p.y - c.p.y));

    if (cos(c.phi) * (p.x - c.p.x) + sin(c.phi) * (p.y - c.p.y) < 0)
    {
        visible = 0;
        return;
    }

    for (int i = 0; i < (int)(dist / 128); i++)
    {
        if (w.h[(int)(c.p.x / 128 + (p.x - c.p.x) / dist * i)][(int)(c.p.y / 128 + (p.y - c.p.y) / dist * i)] > (int)(c.p.z / 128 + (p.z - c.p.z) / dist * i))
        {
            visible = 0;
            return;
        }
    }

    visible = 1;
}