#include<stdio.h>

int main(void){
	int n;
	scanf("%d",&n);
	double *px=new double[n];
	double *py=new double[n];
	printf("input %d points (x,y):\n",n);
	for(int i=0;i<n;i++){
		scanf("%lf",&px[i]);
		scanf("%lf",&py[i]);
	}
	
	double d=((px[0]-px[1])*(px[0]-px[1])+(py[0]-py[1])*(py[0]-py[1])),x1=px[0],y1=py[0],x2=px[1],y2=py[1];

	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j])<d){
				d=((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
				x1=px[i];
				y1=py[i];
				x2=px[j];
				y2=py[j];
			}
	
	printf("The closest two points are (%lg,%lg),(%lg,%lg)\n",x1,y1,x2,y2);

	return 0;
}
