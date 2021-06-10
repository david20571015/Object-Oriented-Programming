#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[50],*p;
	fgets(s,50,stdin);
	s[strlen(s)-1]='\0';
	p=strtok(s," ");
	
	while(p){
		printf("%d ",strlen(p));
		p=strtok(NULL," ");
	}

    return 0;
}
