#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int main(void)
{
	char s[41],*p;
	vector<char*> str;
	fgets(s,41,stdin);
	s[strlen(s)-1]='\0';
	int space=40,n=0,count=0;
		
	for(int i=0;i<strlen(s);i++)
		if(s[i]!=' ')
			space--;
	
	p=strtok(s," ");
	while(p){
		n++;
		str.push_back(p);
		p=strtok(NULL," ");
	}
	n--;
	
	for(int i=0;i<str.size();i++){
		fputs(str[i],stdout);
		for(int j=0;j<space/n&&count<str.size()-1;j++)
			printf(" ");
		if(count<space%n)
			printf(" ");		
		count++;
	}
	
    return 0;
}
