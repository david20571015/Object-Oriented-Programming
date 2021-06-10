#include<stdio.h>
#include<string.h>

struct student{
	char name[20], id[7];
	int chi,eng,math,total;
};

void input(struct student *data,int n){
	printf("Please input %d data (name/id/chinese/english/math) :\n",n);
	for(int i=0;i<n;i++){
		scanf("%s %s %d %d %d",&data[i].name,&data[i].id,&data[i].chi,&data[i].eng,&data[i].math);
		data[i].total=data[i].chi+data[i].eng+data[i].math;
	}
}

void output(struct student *data,int n){
	printf("name                id     chinese   english   math      total\n");
	for(int i=0;i<n;i++)
		printf("%-20s%-7s%-10d%-10d%-10d%-3d\n",data[i].name,data[i].id,data[i].chi,data[i].eng,data[i].math,data[i].total);
}

void swap(struct student *data,int i,int j){
	char t1;
	int t2;
	for(int k=0;k<20;k++){
		t1=data[i].name[k];
		data[i].name[k]=data[j].name[k];
		data[j].name[k]=t1;
	}

	for(int k=0;k<7;k++){
		t1=data[i].id[k];
		data[i].id[k]=data[j].id[k];
		data[j].id[k]=t1;
	}

	t2=data[i].chi;
	data[i].chi=data[j].chi;
	data[j].chi=t2;

	t2=data[i].eng;
	data[i].eng=data[j].eng;
	data[j].eng=t2;

	t2=data[i].math;
	data[i].math=data[j].math;
	data[j].math=t2;

	t2=data[i].total;
	data[i].total=data[j].total;
	data[j].total=t2;
}

void sort(struct student *data,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(data[i].total>data[j].total)
				swap(data,i,j);
			else if(data[i].total==data[j].total){
				if(data[i].chi>data[j].chi)
					swap(data,i,j);
				else if(data[i].chi==data[j].chi){
					if(data[i].eng>data[i].eng)
						swap(data,i,j);
					else if(data[i].eng==data[i].eng){
						if(data[i].math>data[i].math)
							swap(data,i,j);
						else if(data[i].math==data[j].math){
							if(strcmp(data[i].id,data[j].id)>0)
								swap(data,i,j);
						}
					}
				}
			}
		}
	}
}



int main(void){
	int n;
	printf("Please input the number of students: ");
	scanf("%d",&n);
	struct student *data=new struct student[n];
	input(data,n);
	sort(data,n);
	output(data,n);
	delete []data;
	return 0;
}
