#include <stdio.h>
#include <graphics.h>

class Rectangle
{
private:
	int x;
	int y;
	int width;
	int height;

public:
	Rectangle()
	{
		x = y = width = height = 0;
	}
	Rectangle(int xx, int yy, int w, int h)
	{
		x = xx;
		y = yy;
		width = w;
		height = h;
	}
	int calPerimeter();
	int calArea();
	void draw();
};

int Rectangle::calPerimeter()
{
	return (width + height) * 2;
}

int Rectangle::calArea()
{
	return width * height;
}

void Rectangle::draw()
{
	bar(x, y, x + width, y + height);
}

int main(void)
{
	initwindow(1000, 1000);
	int x, y, w, h;

	while (scanf("%d %d %d %d", &x, &y, &w, &h) != EOF)
	{
		class Rectangle r(x, y, w, h);
		printf("Perimeter:%-5dArea:%-5d\n", r.calPerimeter(), r.calArea());
		r.draw();
	}

	return 0;
}
