#include<stdio.h>
#include<stdlib.h>
#include<time.h>

enum suit{clubs,diamonds,hearts,spades};

struct card{
	int cardsuit;
	int value;
};

void shuffle(card deck[52]){
	srand(time(NULL));
	card tmp;
	int t;
	for(int i=0;i<52;i++){
		t=rand()%52;
		tmp=deck[i];
		deck[i]=deck[t];
		deck[t]=tmp;
	}
}

int main(void){
	card deck[52];
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			deck[i*13+j]={i,j};

	shuffle(deck);

	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++)
			printf("%2d %2d  ",deck[i*13+j].cardsuit+1,deck[i*13+j].value+1);
		printf("\n");
	}
	return 0;
}
