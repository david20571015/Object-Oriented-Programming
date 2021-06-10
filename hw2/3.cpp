#include<stdio.h>
#include<vector>
using namespace std;

int main(void){
	int len1,len2;

	printf("The length of Array 1: ");
	scanf("%d",&len1);
	double *a1=new double[len1];
	printf("Input %d numbers: ",len1);
	for(int i=0;i<len1;i++)
		scanf("%lf",&a1[i]);

	printf("The length of Array 2: ");
	scanf("%d",&len2);
	double *a2=new double[len2];
	printf("Input %d numbers: ",len2);
	for(int i=0;i<len2;i++)
		scanf("%lf",&a2[i]);

	int f1=0,f2=0;
	vector<double> arr;
	while((f1<len1)&&(f2<len2)){
		if(a1[f1]<a2[f2]){
			arr.push_back(a1[f1]);
			f1++;
		}
		else if(a1[f1]==a2[f2]){
			arr.push_back(a1[f1]);
			f1++;
			f2++;
		}
		else if(a1[f1]>a2[f2]){
			arr.push_back(a2[f2]);
			f2++;
		}
	}

	if(f1<len1&&f2==len2)
		for(int i=f1;i<len1;i++)
			arr.push_back(a1[i]);
	if(f1==len1&&f2<len2)
		for(int i=f2;i<len2;i++)
			arr.push_back(a2[i]);
	
	delete []a1;
	delete []a2;

	for(int i=0;i<arr.size();i++)
		printf("%lg  ",arr[i]);
	printf("\n");

	return 0;
}
