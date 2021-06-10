#include<stdio.h>

int main(void){
	int n;
	scanf("%d",&n);
	int *a=new int[n+1];
	int *b=new int[n+1];

	for(int i=0;i<n;i++){
		a[i]=i;
		b[i]=1;
	}

	int x=2;
	while(x*x<=n){
		for(int i=x*x;i<=n;i+=x)
			b[i]=0;
		x++;
		while(b[x]==0)
			x++;
	}

	for(int i=2;i<=n;i++){
		if(b[i])
			printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
