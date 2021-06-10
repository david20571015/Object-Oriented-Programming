#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Grid 16
#define Width 8

#define map(i, max1, min1, max2, min2) ((i - min1) * (max2 - min2) / (max1 - min1) + min2)
#define dot(x1, y1, x2, y2) (x1 * x2 + y1 * y2)
#define f(t) (t * t * t * (t * (t * 6.0 - 15.0) + 10.0))

double lerp(double d1, double d2, double t)
{
    return d1 * (1.0 - f(t)) + d2 * f(t);
}

void perlin_noise(int **terrain, int random_seed)
{
    double grad[8][2] = {{sqrt(2), 0}, {1, 1}, {0, sqrt(2)}, {-1, 1}, {-sqrt(2), 0}, {-1, -1}, {0, -sqrt(2)}, {1, -1}};
    double height[Grid * Width][Grid * Width];
    int print[Grid * Width][Grid * Width];
    double g[Grid][Grid][2];

    double max = -200, min = 200;

    srand(random_seed);
    for (int i = 0; i < Grid; i++)
        for (int j = 0; j < Grid; j++)
        {
            int t = rand() % 8;
            g[i][j][0] = grad[t][0];
            g[i][j][1] = grad[t][1];
        }

    for (int i = 0; i < Grid * Width; i++)
        for (int j = 0; j < Grid * Width; j++)
        {
            int v[4][2] = {{i % Grid, j % Grid},
                           {i % Grid - Grid, j % Grid},
                           {i % Grid - Grid, j % Grid - Grid},
                           {i % Grid, j % Grid - Grid}};

            int dotv[4] = {dot(v[0][0], v[0][1], g[i / Grid][j / Grid][0], g[i / Grid][j / Grid][1]),
                           dot(v[1][0], v[1][1], g[i / Grid + 1][j / Grid][0], g[i / Grid + 1][j / Grid][1]),
                           dot(v[2][0], v[2][1], g[i / Grid + 1][j / Grid + 1][0], g[i / Grid + 1][j / Grid + 1][1]),
                           dot(v[3][0], v[3][1], g[i / Grid][j / Grid + 1][0], g[i / Grid][j / Grid + 1][1])};

            height[i][j] = lerp(lerp(dotv[0], dotv[1], (i % Grid) / (double)Grid), lerp(dotv[3], dotv[2], (i % Grid) / (double)Grid), (j % Grid) / (double)Grid);

            if (height[i][j] > max)
                max = height[i][j];
            if (height[i][j] < min)
                min = height[i][j];
        }

    for (int i = 0; i < Grid * Width; i++)
        for (int j = 0; j < Grid * Width; j++)
            terrain[i][j] = (int)map(height[i][j], max, min, 16, 1);
}