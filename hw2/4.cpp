#include<stdio.h>

int main(void){
	int score[101]={0};
	int s;
	
	for(int i=0;i<=100;i++){
		scanf("%d",&s);
		if(s==-999)
			break;
		else
			score[s]++;
	}

	printf("Test Score      Count\n");
	for(int i=0;i<=100;i++)
		if(score[i]!=0)
			printf("   %3d          %3d\n",i,score[i]);

	return 0;
}
