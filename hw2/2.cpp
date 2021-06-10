#include<stdio.h>
#include<vector>
using namespace std;

int main(void){
	int n;
	vector<int> bin;

	scanf("%d",&n);
	printf("The position of 1's in the binary representation of %d are ",n);
	while(n){
		bin.push_back(n%2);
		n/=2;		
	}
	
	for(int i=0;i<bin.size();i++){
		if(bin[i])
			printf("%d, ",i);
	}
	printf("\n");

	return 0;
}
