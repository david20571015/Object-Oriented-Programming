#include<stdio.h>
#define W 8
#define I 4

int main(void){
	int value[I+1][W+1]={0};
	int v[I]={15,10,9,5}, w[I]={1,5,3,4};


	for(int i=1;i<=I;i++){
		for(int j=1;j<=W;j++){
			if(w[i-1]>j)
				value[i][j]=value[i-1][j];
			else{
				if((v[i-1]+value[i-1][j-w[i-1]])>value[i-1][j])
					value[i][j]=v[i-1]+value[i-1][j-w[i-1]];
				else
					value[i][j]=value[i-1][j];
			}
		}
	}

	printf("     ");
	for(int i=0;i<=W;i++)
		printf("w=%d  ",i);
	printf("\n");
	for(int i=0;i<=I;i++){
		printf("i=%d  ",i);
		for(int j=0;j<=W;j++)
			printf(" %2d ",value[i][j]);
		printf("\n");
	}

	return 0;
}
