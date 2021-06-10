#include<stdio.h>

char win(char a[3][3]){
	if(a[0][0]==a[1][1]&&a[1][1]==a[2][2])
		return a[0][0];
	if(a[0][2]==a[1][1]&&a[1][1]==a[2][0])
		return a[0][2];
	for(int i=0;i<3;i++){
		if(a[i][0]==a[i][1]&&a[i][1]==a[i][2])
			return a[i][0];
		if(a[0][i]==a[1][i]&&a[1][i]==a[2][i])
			return a[0][i];
	}
	return 'd';
}

void print_board(char a[3][3]){
	printf("  A B C\n");
	for(int i=0;i<3;i++){
		printf("%d ",i+1);
		for(int j=0;j<3;j++)
			printf("%c ",a[i][j]);
		printf("\n");
	}
}


int main(void){
	char a[3][3];
	int f,p1_win=0,p2_win=0,draw=0;
	char conti='Y';
	int colunm;
	char row;
	while(conti=='Y'){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				a[i][j]='.';
		f=0;
		for(int t=0;t<9&&f==0;t++){
			print_board(a);
			printf("Player %d 's turn(row colunm): ",t%2+1);
			scanf(" %c %d",&row,&colunm);
			a[colunm-1][row-'A']=(t%2)?'X':'O';

			if(win(a)=='O'){
				printf("Player 1 win.\n");
				p1_win++;
				printf("p1 : draw : p2 = %d : %d : %d\n",p1_win,draw,p2_win);
				printf("Continue?(Y/N) ");
				scanf(" %c",&conti);
				f=1;
			}
			else if(win(a)=='X'){
				printf("Player 2 win.\n");
				p2_win++;
				printf("p1 : draw : p2 = %d : %d : %d\n",p1_win,draw,p2_win);
				printf("Continue?(Y/N) ");
				scanf(" %c",&conti);
				f=1;
			}
			else if(win(a)=='d'&&t==8){
				printf("Draw.\n");
				draw++;
				printf("p1 : draw : p2 = %d : %d : %d\n",p1_win,draw,p2_win);
				printf("Continue?(Y/N) ");
				scanf(" %c",&conti);
				f=1;
			}
		}
	}
	return 0;
}
