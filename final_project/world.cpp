#include "perlin_noise.cpp"
#include "cube.cpp"

class World
{
public:
    int rand_seed;
    int **h;
    Cube ***terrain;
    void create_terrain(int);
};

void World::create_terrain(int rand_seed)
{
    h = new int *[128];
    for (int i = 0; i < 128; i++)
        h[i] = new int[128];
    perlin_noise(h, rand_seed);

    terrain = new Cube **[128];
    for (int i = 0; i < 128; i++)
    {
        terrain[i] = new Cube *[128];
        for (int j = 0; j < 128; j++)
            terrain[i][j] = new Cube[16];
    }

    for (int i = 0; i < 128; i++)
        for (int j = 0; j < 128; j++)
        {
            for (int k = 0; k < h[i][j]; k++)
            {
                Point p;
                p.x = i * 128;
                p.y = j * 128;
                p.z = k * 128;
                Cube cu(p, 1);
                terrain[i][j][k] = cu;
            }
            for (int k = h[i][j]; k < 16; k++)
            {
                Point p;
                p.x = i * 128;
                p.y = j * 128;
                p.z = k * 128;
                Cube cu(p, -1);
                terrain[i][j][k] = cu;
            }
        }
}