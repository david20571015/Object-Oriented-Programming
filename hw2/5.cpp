#include<stdio.h>
#include<stdlib.h>
#define C 9
#define R 15

int main(void){
	char seat[C][R],conti='y',colunm;
	int ticket,row;

	while(conti=='y'){
		printf("1,First class\n2,Business class\n3,Economy class\n");
		printf("Choose your Ticket type: ");
		scanf("%d",&ticket);

		printf("       ");
		for(int i=0;i<C;i++)
			printf("%c ",'A'+i);
		printf("\n");
		for(int j=0;j<R;j++){
			printf("Row %-2d ",j+1);
			for(int i=0;i<C;i++){
				if(seat[i][j]=='x')
					printf("x ");
				else
					printf("* ");
			}
			printf("\n");
		}

		switch(ticket){
			case 1:
				printf("(Row 1 ~ Row 2)\n");
				break;
			case 2:
				printf("(Row 3 ~ Row 8)\n");
				break;
			case 3:
				printf("(Row 9 ~ Row 15)\n");
		}

		printf("Choose your seat(Row/Colunm): ");
		scanf("%d %c",&row,&colunm);
		seat[colunm-'A'][row-1]='x';

		printf("Continue?(y/n) ");
		scanf(" %c",&conti);
	}
	printf("\n");

	return 0;
}
