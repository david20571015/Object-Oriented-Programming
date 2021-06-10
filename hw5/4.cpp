#include <stdio.h>
#include <string.h>

int main(void)
{	
	char bin[20],dec[10],tmp;
	fgets(bin,20,stdin);
	int d=0,count=1;
	
	for(int i=0;bin[i+1]!='\0';i++){	
		d*=2;
		d+=bin[i]-'0';
	}
	printf("%d\n",d);
	
    return 0;
}
