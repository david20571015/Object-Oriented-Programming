#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s;
	s = new char[11];
	strcpy(s,"0123456789");
    char *t;

    for (int i = 0; i < 10; i++)
    {
        t=strchr(s,'0'+i);
        strncat (t,s,1);
        strcpy(s,t);
        s[10]='\0';
        fputs(s,stdout);
        printf("\n");
    }

    return 0;
}
