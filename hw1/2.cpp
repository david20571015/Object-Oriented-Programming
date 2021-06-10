#include<stdio.h>

int main(void){
	int **a=new int*[4];
	for(int i=0;i<4;i++)
		a[i]=new int[3];
	int **b=new int*[3];
	for(int i=0;i<3;i++)
		b[i]=new int[4];

	for(int j=0;j<3;j++){
		for(int i=0;i<4;i++)
			scanf("%d",&a[i][j]);
	}
	for(int j=0;j<4;j++){
		for(int i=0;i<3;i++)
			scanf("%d",&b[i][j]);
	}

	int tem;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			tem=0;
			for(int k=0;k<4;k++){
				tem+=a[k][i]*b[j][k];
			}
			printf("%d ",tem);
		}
		printf("\n");
	}

	for(int i=0;i<4;i++)
		delete []a[i];
	delete []a;
	for(int i=0;i<3;i++)
		delete []b[i];
	delete []b;
	
	return 0;
}
