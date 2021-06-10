#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

struct book{
	int cat_num;
	char title[30];
	char author[10];
	int price;
	bool issued;
};

void options(int &op){
	printf("(1)Add book information\n");
	printf("(2)Display book information\n");
	printf("(3)List all books of given author\n");
	printf("(4)List the title of specified book\n");
	printf("(5)List the count of books in the library\n");
	printf("(6)List the books in the order of catalog number\n");
	printf("(7)Exit\n");
	scanf("%d",&op);
}

void add_inf(vector<book> &lib){
	book t;
	printf("Catalog number: ");
	scanf("%d",&t.cat_num);
	printf("Title of the book: ");
	scanf("%s",t.title);
	printf("Author name: ");
	scanf("%s",t.author);
	printf("Price of the book: ");
	scanf("%d",&t.price);
	printf("Issued(1/0): ");
	scanf("%d",&t.issued);
	lib.push_back(t);
}

void display(vector<book> lib){
	char t[30];
	printf("Book name: ");
	scanf("%s",t);
	for(int i=0;i<lib.size();i++){
		if(strcmp(lib[i].title,t)==0){
			printf("Catalog: %d\n",lib[i].cat_num);
			printf("Author: %s\n",lib[i].author);
			printf("Price: %d\n",lib[i].price);
			printf("Issued: %s\n",(lib[i].issued)?"Yes":"No");
			break;
		}
	}
}


void list_au(vector<book> lib){
	char a[10];
	printf("Author: ");
	scanf("%s",a);
	for(int i=0;i<lib.size();i++)
		if(strcmp(lib[i].author,a)==0)
			printf("%s\n",lib[i].title);
}

void list_order(vector<book> &lib){
	book t;
	for(int i=0;i<lib.size()-1;i++)
		for(int j=i+1;j<lib.size();j++)
			if(lib[i].cat_num>lib[j].cat_num){
				t=lib[i];
				lib[i]=lib[j];
				lib[j]=t;
			}
	for(int i=0;i<lib.size();i++){
		if(lib[i].cat_num!=lib[i-1].cat_num)
			printf("%-3d:\n",lib[i].cat_num);
		printf("%s\n",lib[i].title);
	}
}

int main(void){
	vector<book> lib;
	int op;

	while(op!=7){
		options(op);

		switch(op){
			case 1:
				add_inf(lib);
				break;
			case 2:
				display(lib);
				break;
			case 3:
				list_au(lib);
				break;
			case 4:
				break;
			case 5:
				printf("%d\n",lib.size());
				break;
			case 6:
				list_order(lib);
				break;
		}
	}
	return 0;
}
