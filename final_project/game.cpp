#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "world.cpp"
#include "menu.cpp"
#include "monster.cpp"

#define window_w 1600
#define window_h 1000

#define W_KEY 0x57
#define A_KEY 0x41
#define S_KEY 0x53
#define D_KEY 0x44

int main()
{
    int seed = menu();
    World w;
    w.create_terrain(seed);

    Monster *m = new Monster[10];
    srand(time(NULL));
    int timer = 0;
    int pop = 0;

    Camera c;
    c.p.x = 63 * 128 + 64;
    c.p.y = 63 * 128 + 64;
    c.p.z = 17 * 128;
    c.phi = 0;
    c.theta = 3.14;

    double mouse_pos[2] = {window_w / 2, window_h / 2};

    int build_mode[2][8] = {{1300, 730, 1599, 800, 1599, 960, 1160, 820}, {1160, 820, 1599, 960, 1599, 999, 1160, 999}};
    int sword[5][3][10] = {
        {{1340, 999, 1550, 450, 1490, 280, 1340, 390, 1190, 999}, {1490, 280, 1550, 450, 1598, 465, 1598, 440, 1530, 290}, {1550, 450, 1330, 999, 1380, 999, 1598, 450}},
        {{930, 460, 940, 530, 1010, 999, 1030, 999, 950, 530}, {950, 530, 1030, 999, 1060, 999, 980, 530, 950, 530}, {950, 530, 980, 530, 960, 460, 930, 460}},
        {{730, 620, 750, 680, 850, 999, 860, 999, 745, 640}, {745, 640, 860, 999, 890, 999, 760, 630, 745, 640}, {745, 640, 760, 630, 750, 610, 730, 620}},
        {{930, 460, 940, 530, 1010, 999, 1030, 999, 950, 530}, {950, 530, 1030, 999, 1060, 999, 980, 530, 950, 530}, {950, 530, 980, 530, 960, 460, 930, 460}},
        {{1340, 999, 1550, 450, 1490, 280, 1340, 390, 1190, 999}, {1490, 280, 1550, 450, 1598, 465, 1598, 440, 1530, 290}, {1550, 450, 1330, 999, 1380, 999, 1598, 450}}};
    int warning[20] = {0, 0, 1599, 0, 1599, 999, 0, 999, 0, 0, 30, 30, 1569, 30, 1569, 969, 30, 969, 30, 30};

    int sword_timer = 0;
    bool building = 0;
    int v = 0;

    int cur_page = 0;
    initwindow(window_w, window_h, "Minecraft");
    setbkcolor(COLOR(200, 255, 255));

    while (1)
    {
        cur_page = -cur_page + 1;
        setactivepage(cur_page);
        cleardevice();

        double cur_x = c.p.x / 128, cur_y = c.p.y / 128, cur_z = c.p.z / 128;

        double sinphi = sin(c.phi);
        double sintheta = sin(c.theta);
        double cosphi = cos(c.phi);
        double costheta = cos(c.theta);

        if (timer == 0 && !m[pop].alive)
        {
            m[pop].create_monster(c, w);
            if (pop < 10)
                pop++;
            else
                pop = 0;
        }
        timer++;
        timer %= 100;

        if (GetAsyncKeyState(W_KEY) && cur_z >= w.h[(int)(cur_x + cosphi)][(int)(cur_y + sinphi)] + 1)
        {
            c.p.x += 20 * cosphi;
            c.p.y += 20 * sinphi;
        }
        if (GetAsyncKeyState(S_KEY) && cur_z >= w.h[(int)(cur_x - cosphi)][(int)(cur_y - sinphi)] + 1)
        {
            c.p.x -= 20 * cosphi;
            c.p.y -= 20 * sinphi;
        }
        if (GetAsyncKeyState(D_KEY) && cur_z >= w.h[(int)(cur_x - sinphi)][(int)(cur_y + cosphi)] + 1)
        {
            c.p.x -= 20 * sinphi;
            c.p.y += 20 * cosphi;
        }
        if (GetAsyncKeyState(A_KEY) && cur_z >= w.h[(int)(cur_x + sinphi)][(int)(cur_y - cosphi)] + 1)
        {
            c.p.x += 20 * sinphi;
            c.p.y -= 20 * cosphi;
        }

        c.p.z += v;
        if (cur_z > w.h[(int)(cur_x)][(int)(cur_y)] + 2)
            v -= 5;
        else if (cur_z <= w.h[(int)(cur_x)][(int)(cur_y)] + 2)
            v = 0;
        if (GetAsyncKeyState(0x20) && cur_z <= w.h[(int)(cur_x)][(int)(cur_y)] + 2)
            v = 30;

        c.phi = (mousex() - mouse_pos[0]) / 100 + 1.57;
        if (mousey() < 450 && mousey() > 275)
            c.theta = (mouse_pos[1] - mousey()) / 100 + 1.57;

        int x, y;

        if (ismouseclick(WM_RBUTTONDOWN))
        {
            clearmouseclick(WM_RBUTTONDOWN);
            building = !building;
        }

        double n;
        if (building)
        {
            for (n = 0; n < 5; n += 0.5)
            {
                if (w.terrain[(int)(cur_x + cosphi * n)][(int)(cur_y + sinphi * n)][(int)(cur_z - sintheta * n)].texture > 0)
                {
                    if (w.h[(int)(cur_x + cosphi * (n - 1))][(int)(cur_y + sinphi * (n - 1))] == (int)(cur_z - sintheta * (n - 1)))
                    {
                        w.terrain[(int)(cur_x + cosphi * (n - 1))][(int)(cur_y + sinphi * (n - 1))][(int)(cur_z - sintheta * (n - 1))].texture = 2;
                        w.h[(int)(cur_x + cosphi * (n - 1))][(int)(cur_y + sinphi * (n - 1))]++;
                    }
                    break;
                }
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN))
        {
            if (building)
            {
                clearmouseclick(WM_LBUTTONDOWN);
                if (w.terrain[(int)(cur_x + cosphi * (n - 1))][(int)(cur_y + sinphi * (n - 1))][(int)(cur_z - sintheta * (n - 1))].texture == 2)
                {
                    building = !building;
                    w.terrain[(int)(cur_x + cosphi * (n - 1))][(int)(cur_y + sinphi * (n - 1))][(int)(cur_z - sintheta * (n - 1))].texture = 1;
                }
            }
            else
            {
                sword_timer++;
                if (sword_timer == 4)
                {
                    sword_timer = 0;
                    clearmouseclick(WM_LBUTTONDOWN);
                }
                for (int i = 0; i < 10; i++)
                {
                    if (m[i].alive && (c.p.x - m[i].p.x) * (c.p.x - m[i].p.x) + (c.p.y - m[i].p.y) * (c.p.y - m[i].p.y) < 40000)
                        m[i].alive = 0;
                }

                if (w.terrain[(int)(cur_x + cosphi)][(int)(cur_y + sinphi)][(int)(cur_z - sintheta)].texture == 1 && w.h[(int)(cur_x + cosphi)][(int)(cur_y + sinphi)] == (int)(cur_z - sintheta) + 1)
                {
                    w.terrain[(int)(cur_x + cosphi)][(int)(cur_y + sinphi)][(int)(cur_z - sintheta)].texture = 0;
                    w.h[(int)(cur_x + cosphi)][(int)(cur_y + sinphi)]--;
                }
            }
        }

        setcolor(0);
        for (int z = 0; z <= int(cur_z) - 1; z++)
            for (double r = 10; r >= 0; r -= 0.5)
                for (double i = c.phi - 1; i <= c.phi + 1; i += 0.1)
                {
                    x = (cos(i) * r) + cur_x;
                    y = (sin(i) * r) + cur_y;
                    if (w.terrain[x][y][z].texture > 0)
                        w.terrain[x][y][z].show(c, w.h);
                }

        for (int z = 15; z >= int(cur_z); z--)
            for (double r = 10; r >= 0; r -= 0.5)
                for (double i = c.phi - 1; i <= c.phi + 1; i += 0.1)
                {
                    x = (cos(i) * r) + cur_x;
                    y = (sin(i) * r) + cur_y;
                    if (w.terrain[x][y][z].texture > 0)
                        w.terrain[x][y][z].show(c, w.h);
                }

        if (building && w.terrain[(int)(cur_x + cosphi * (n - 1))][(int)(cur_y + sinphi * (n - 1))][(int)(cur_z - sintheta * (n - 1))].texture == 2)
        {
            w.terrain[(int)(cur_x + cosphi * (n - 1))][(int)(cur_y + sinphi * (n - 1))][(int)(cur_z - sintheta * (n - 1))].texture = 0;
            w.h[(int)(cur_x + cosphi * (n - 1))][(int)(cur_y + sinphi * (n - 1))]--;
        }

        for (int i = 0; i < 10; i++)
        {
            if (m[i].alive)
            {
                m[i].vis(c, w);
                if (m[i].visible)
                    m[i].show(c);
                m[i].move(c, w);
                if ((c.p.x - m[i].p.x) * (c.p.x - m[i].p.x) + (c.p.y - m[i].p.y) * (c.p.y - m[i].p.y) < 90000)
                {
                    setcolor(4);
                    setfillstyle(1, 4);
                    fillpoly(10, warning);
                }
            }
        }

        setcolor(0);
        if (building)
        {
            setfillstyle(1, 54422086);
            fillpoly(4, build_mode[0]);
            setfillstyle(1, 50796070);
            fillpoly(4, build_mode[1]);
        }
        else
        {
            setfillstyle(1, 58489980);
            fillpoly(5, sword[sword_timer][0]);
            fillpoly(5, sword[sword_timer][1]);
            fillpoly(4, sword[sword_timer][2]);
        }

        setvisualpage(cur_page);
    }
    return 0;
}
