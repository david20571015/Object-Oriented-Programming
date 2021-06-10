#include <stdio.h>
#include <string.h>

int main(void)
{
    char b1[20], b2[20], *b ; 
	int c = 0;
	scanf(" ");
    fgets(b1,20,stdin);
    scanf(" ");
    fgets(b2,20,stdin);
    puts(b1);
    puts(b2);

    int len = (strlen(b1) > strlen(b2)) ? strlen(b1) : strlen(b2);

    for (int i = 0; i < len; i++)
    {
        if (b1[i]-'0'+b2[i]-'0'+c == '0')
        {
            b[i]='0';
            c=0;
        }
        else if(b1[i]-'0'+b2[i]-'0'+c == '1')
        {
            b[i]='1';
            c=0;
        }
        else if(b1[i]-'0'+b2[i]-'0'+c =='2')
        {
            b[i]='0';
            c=1;          
        }
        else if(b1[i]-'0'+b2[i]-'0'+c =='3')
        {
            b[i]='1';
            c=1;
        }        
    }
    fputs(b,stdout);
    return 0;
}
