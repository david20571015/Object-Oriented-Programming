#include<stdio.h>

void combonation(const int *num, int sum, int rest,int d, int *c,int n,int len){
	if(rest==0&&sum%d==0)
		(*c)++;
	else if(n<len){
		combonation(num,sum       ,rest  ,d,c,n+1,len);
		combonation(num,sum+num[n],rest-1,d,c,n+1,len);
	}
}

int main(void){
	int n,k,d,c;
	int times;
	scanf("%d",&times);
	int *Case=new int[times];
	for(int count=0;count<times;count++){
		scanf("%d %d %d",&n,&k,&d);
		c=0;
		int *num=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);

		combonation(num,0,k,d,&c,0,n);
		
		Case[count]=c;
	}
	for(int i=0;i<times;i++)
		printf("Case %2d: %2d\n",i+1,Case[i]);

	return 0;
}
