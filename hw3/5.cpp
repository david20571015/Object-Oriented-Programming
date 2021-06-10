#include<stdio.h>
#include<math.h>

struct point{
	int x,y;
};

struct circle{
	point p;
	double radius;
};

double area(circle c){
	return c.radius*c.radius*M_PI;
}

int main(void){
	circle c;
	printf("Input x, y and radius: ");
	scanf("%d %d %lf",&c.p.x,&c.p.x,&c.radius);
	printf("%lf\n",area(c));
	return 0;
}
