#include <stdio.h>
#include <string.h>

int main(void)
{	
	int num,count,pos;
	scanf("%d",&num);
	
	char **s=new char *[num];
	
	for(int i=0;i<num;i++){
		s[i]=new char[1000];
		scanf(" ");
		fgets(s[i],1000,stdin);
		
		count=pos=0;
		s[i][strlen(s[i])-1]='\0';
		
		for(int j=0;j<strlen(s[i]);j++){
			if(s[i][j]<'0'||s[i][j]>'9')
				continue;
				
			if(s[i][j]==s[i][j+1])
				count++;
			else{
				printf("%d%c",count+1,s[i][j]);
				count=0;
			}
		}
	}

    return 0;
}
