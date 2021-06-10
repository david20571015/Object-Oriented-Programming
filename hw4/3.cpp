#include<stdio.h>
#include<vector>
using namespace std;

class LargeInt{
	int num[50];
	char sign;

	public:
		LargeInt();
		void input();
		void input(int);
		void output();
		int size();
		int cmp(LargeInt);
		LargeInt operator+(LargeInt);
		void operator+=(LargeInt);
		LargeInt operator-(LargeInt);
		LargeInt operator*(LargeInt);
		LargeInt operator*(int);
		LargeInt operator/(LargeInt);
};

struct fix{
	LargeInt larint;
	char oper;
	int item;
};

LargeInt::LargeInt(){
	sign='+';
	for(int i=0;i<50;i++)
		num[i]=0;
}

int LargeInt::size(){
	for(int i=49;i>=0;i--)
		if(num[i]!=0)
			return i;
}

int LargeInt::cmp(LargeInt l){
	for(int i=49;i>=0;i--){
		if(this->num[i]<l.num[i])
			return -1;
		else if(this->num[i]>l.num[i])
			return 1;
	}
	return 0;
}

void LargeInt::output(){
	if(this->sign=='-')
		printf("-");
	if(this->size()==-1)
		printf("%d",0);
	for(int i=this->size();i>=0;i--){
		printf("%d",num[i]);
		if(i%4==0&&i!=0)
			printf(",");
	}
	printf("\n");
}

void LargeInt::input(int n){
	int i=0;
	LargeInt t;
	while(n){
		t.num[i++]=n%10;
		n/=10;
	}
	(*this)=t;
}

void LargeInt::input(){
	char *n=new char[50];
	scanf("%s",n);
	sign=(n[0]=='-')?'-':'+';
	int i=(sign=='-')?1:0;
	int size=i;
	for(int j=i;j<50;j++){
		if(n[j]<='9'&&n[j]>='0')
			size++;
		else
			break;
	}
	for(int j=0;j<size-i;j++)
		num[j]=n[size-j-1]-'0';
	delete []n;
}

LargeInt LargeInt::operator+(LargeInt l){
	LargeInt t;
	if(sign==l.sign){
		t.sign=sign;
		for(int i=0;i<50;i++){
			t.num[i]+=num[i]+l.num[i];
			if(t.num[i]>9)
				t.num[i+1]+=(t.num[i]/10);
				t.num[i]%=10;
		}
	}
	else if(sign=='-'&&l.sign=='+'){
		LargeInt tmp=(*this);
		tmp.sign='+'; 
		t=l-tmp;
	} 
	else if(sign=='+'&&l.sign=='-'){
		l.sign='+';	
		t=(*this)-l;
	}
	return t;
}

void LargeInt::operator+=(const LargeInt l){
	(*this)=(*this)+l;
}

LargeInt LargeInt::operator-(LargeInt l){
	LargeInt t;
	if(sign==l.sign){
		for(int i=0;i<50;i++){
			t.num[i]+=(num[i]-l.num[i])*(this->cmp(l));
			if(t.num[i]<0){
				t.num[i]+=10;
				t.num[i+1]--;
			}
		}
		t.sign=(this->cmp(l)==-1)?'-':'+';
		if(sign=='-'&&l.sign=='-')
			t.sign=(t.sign=='-')?'+':'-';		
	}
	else if(sign=='-'&&l.sign=='+'){
		LargeInt tmp=(*this);
		tmp.sign='+'; 
		t=l+tmp;
		t.sign='-';
	} 
	else if(sign=='+'&&l.sign=='-'){
		l.sign='+';	
		t=(*this)+l;
	}	
	return t;
}

LargeInt LargeInt::operator*(LargeInt l){
	LargeInt t;
	for(int i=0;i<50;i++){
		for(int j=0;j<=i;j++)
			t.num[i]+=num[j]*l.num[i-j];
		if(t.num[i]>9){
			t.num[i+1]+=(t.num[i]/10);
			t.num[i]%=10;
		}
	}
	t.sign=(this->sign==l.sign)?'+':'-';
	return t;
}

LargeInt LargeInt::operator*(int n){
	LargeInt t,times;
	times.input(n);
	t=(*this)*times;	
	return t;
}

LargeInt LargeInt::operator/(LargeInt l){
	LargeInt t,digit,li10,times,tmp=(*this);
	li10.input(10);
	tmp.sign='+';
	l.sign='+';
	for(int i=(tmp.size()-l.size());i>=0;i--){
		digit.input(1);
		for(int j=0;j<i;j++)
			digit=digit*li10;
		for(int j=0;j<=10;j++){
			times.input(j);
			if(tmp.cmp(l*times*digit)==-1){
				t.num[i]=j-1;
				times.input(j-1);
				tmp=tmp-(l*times*digit);
				j=11;
			}
		}
	}
	t.sign=(this->sign==l.sign)?'+':'-';
	return t;
}

int priority(char op) { 
    switch(op) { 
        case '+':
		case '-': 
			return 1;
        case '*':
		case '/':
			return 2;
        default:
			return 0;
    } 
}

void InToPost(char *infix, char *postfix){
	vector<char> oper;
	oper.push_back('\0');
	int i,j;
	for(i=0,j=0;infix[i]!='\0';i++){
		switch(infix[i]){
			case '(':{
				oper.push_back('(');
				break;
			}
			case '+':
			case '-':
			case '*':
			case '/':{
				while(priority(oper.back())>=priority(infix[i])){
					postfix[j++]=oper.back();
					oper.pop_back();
				}
				oper.push_back(infix[i]);
				break;
			}
			case ')':{
				while(oper.back()!='('){
					postfix[j++]=oper.back();
					oper.pop_back();
				}
				oper.pop_back();
				break;
			}
			case ' ':
				break;
			default:{
				postfix[j++]=infix[i];
				break;
			}					
		}
	}
	while(oper.size()>0){
		postfix[j++]=oper.back();
		oper.pop_back();
	}
}

void trans(char* postfix,fix* f,LargeInt n[4]){
	for(int i=0;postfix[i]!='\0';i++){
		switch(postfix[i]){
			case 'x':
				f[i].larint=n[0];
				f[i].item=1;
				break;
			case 'y':
				f[i].larint=n[1];
				f[i].item=1;
				break;
			case 'z':
				f[i].larint=n[2];
				f[i].item=1;
				break;
			case 'w':
				f[i].larint=n[3];
				f[i].item=1;
				break;
			case '+':
				f[i].oper='+';
				f[i].item=2;
				break;
			case '-':
				f[i].oper='-';
				f[i].item=2;
				break;
			case '*':
				f[i].oper='*';
				f[i].item=2;
				break;
			case '/':
				f[i].oper='/';
				f[i].item=2;
				break;
		}	
	}
}

LargeInt PostToLarInt(fix *ff){	
	vector<LargeInt> compute;
	for(int i=0;ff[i].item!=0;i++){
		if(ff[i].item==1)
			compute.push_back(ff[i].larint);
		else if(ff[i].item==2){
			switch(ff[i].oper){
				case '+':
					compute.push_back(compute[compute.size()-2]+compute[compute.size()-1]);
					break;
				case '-':
					compute.push_back(compute[compute.size()-2]-compute[compute.size()-1]);
					break;
				case '*':
					compute.push_back(compute[compute.size()-2]*compute[compute.size()-1]);
					break;
				case '/':
					compute.push_back(compute[compute.size()-2]/compute[compute.size()-1]);
					break;
			}
			compute.erase(compute.end()-2);
			compute.erase(compute.end()-2);
		}	
	}
	return compute.front();
}

int main(void){
	printf("----------1----------\n");
	LargeInt x,y,z,w;
	printf("input 4 LargeInt:\n");
	printf("x= ");
	x.input();
	printf("y= ");
	y.input();
	printf("z= ");
	z.input();
	printf("w= ");
	w.input();
	printf("\n");	
	
	LargeInt l1=x-y,l3=x*z,l4=x/w,l=x+y;
	y+=x;
	printf("x+y => ");
	l.output();
	printf("x-y => ");
	l1.output();
	printf("y+=x => ");
	y.output();
	printf("x*z => ");
	l3.output();
	printf("x/w => ");
	l4.output();
	printf("\n");
	

	printf("----------2----------\n");
	
	char *infix=new char[50];
	char *postfix=new char[50];
	fix *ff=new fix[50];
	for(int i=0;i<50;i++)
		infix[i]='\0';
	
	LargeInt n[4]={x,y,z,w};
	fgets(infix,50,stdin);
	while(fgets(infix,50,stdin)!=NULL){
		for(int i=0;i<50;i++){
			if(infix[i]=='\n')
				infix[i]='\0';
		}
		for(int i=0;i<50;i++){
			postfix[i]='\0';
			ff[i].item=0;
		}
		InToPost(infix,postfix);	
		trans(postfix,ff,n);	
		PostToLarInt(ff).output();
	}
	delete []infix;
	delete []postfix;
	delete []ff;


	return 0;
}
