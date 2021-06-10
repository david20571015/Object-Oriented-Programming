#include <stdio.h>

struct point
{
	int x, y;
};

int quadrant(point p)
{
	if (p.x > 0)
	{
		if (p.y > 0)
			return 1;
		return 4;
	}
	else
	{
		if (p.y > 0)
			return 2;
		return 3;
	}
}

int main(void)
{
	point p;
	printf("Input x and y: ");
	scanf("%d %d", &p.x, &p.y); //cin >> p.x >> p.y;
	printf("(%d,%d) is in %d quadrant\n", p.x, p.y, quadrant(p));
	//cout << "(" << p.x << "," << p.y << ") is in" << quadrant(p) <<"quadrant";
	return 0;
}
