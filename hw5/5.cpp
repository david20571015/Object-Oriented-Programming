#include <stdio.h>
#include <string.h>
#include <conio.h>

void read(char *n, int len)
{
	char tmp[len];
	scanf(" ");
	fgets(tmp, len, stdin);
	for (int i = 0; i < strlen(tmp); i++)
		n[i] = tmp[strlen(tmp) - i - 2];
}

void print(char *n)
{
	char *tmp = new char[strlen(n)];
	for (int i = 0; i < strlen(n); i++)
		tmp[i] = n[strlen(n) - i - 1];
	tmp[strlen(n)] = '\0';
	fputs(tmp, stdout);
}

int main(void)
{
	char n1[40] = "\0", n2[40] = "\0", n[41] = "\0";

	read(n1, 40);
	read(n2, 40);

	int len = (strlen(n1) > strlen(n2)) ? strlen(n1) : strlen(n2);
	int num1, num2;
	for (int i = 0; i < len; i++)
	{
		if (n1[i] != '\0')
			num1 = n1[i] - '0';
		else
			num1 = 0;
		if (n2[i] != '\0')
			num2 = n2[i] - '0';
		else
			num2 = 0;
		n[i] = num1 + num2 + '0';
	}

	for (int i = 0; i < len + 1; i++)
	{
		if (n[i] > '9')
		{
			n[i + 1] += (n[i] - '0') / 10;
			n[i] = (n[i] - '0') % 10 + '0';
		}
		if (n[i] != '\0' && n[i] < '0')
			n[i] += '0';
	}
	print(n);
	return 0;
}
