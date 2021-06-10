#include<stdio.h>

int main(void){
	int x,y;
	scanf("%d %d",&x,&y);

	int **a= new int*[x];
	for(int i=0;i<x;i++)
		a[i]= new int[y];

	for(int j=0;j<y;j++){
		for(int i=0;i<x;i++)
			scanf("%d",&a[i][j]);
	}
	
	
	printf("\n");
	for(int i=0;i<x;i++)
		printf("%d ",a[i][0]);
	printf("\n");
	for(int j=1;j<y-1;j++){
		printf("%d ",a[0][j]);
		for(int i=1;i<x-1;i++){
			if(a[i][j]*a[i+1][j]*a[i-1][j]*a[i][j+1]*a[i][j-1]==1||a[i][j]==0)
				printf("0 ");
			else
				printf("1 ");
		}
		printf("%d",a[x-1][j]);
		printf("\n");
	}
	for(int i=0;i<x;i++)
		printf("%d ",a[i][y-1]);
	printf("\n");


	for(int i=0;i<x;i++)
		delete [] a[i];
	delete []a;

	return 0;
}
