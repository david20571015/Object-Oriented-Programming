#include<stdio.h>

class Fraction{
	int numer;
	int denom;
	int find_gcd(int,int);

	public:
		Fraction(){
			numer=0;
			denom=1;
		}
		Fraction(int n){
			numer=n;
			denom=1;
		}
		Fraction(int n,int d){
			numer=n;
			denom=d;
		}
		void setNum(int);
		void setDen(int);
		int getNum();
		int getDen();
		void increment();
		Fraction operator+(const Fraction &fr);
		Fraction operator*(const Fraction &fr);
		Fraction operator-(const Fraction &fr);
		Fraction operator/(const Fraction &fr);
		void reduce_fraction(int,int);
		void print_fraction();
};

int Fraction::find_gcd(int n1,int n2){
	while(n1*n2){
		if(n1>n2)
			n1%=n2;
		else
			n2%=n1;
	}
	return n1+n2;
}

void Fraction::setNum(int n){
	numer=n;
}

void Fraction::setDen(int d){
	denom=d;
}

void Fraction::increment(){
	numer+=denom;
}

int Fraction::getNum(){
	int n;
	printf("Num= ");
	scanf("%d",&n);
	return n;
}

int Fraction::getDen(){
	int d;
	printf("Den= ");
	scanf("%d",&d);
	return d;
}

Fraction Fraction::operator+(const Fraction &fr){
	Fraction t;
	t.numer=numer*fr.denom + fr.numer*denom;
	t.denom=denom*fr.denom;
	return t;
}

Fraction Fraction::operator*(const Fraction &fr){
	Fraction t;
	t.numer=numer*fr.numer;
	t.denom=denom*fr.denom;
	return t;
}

Fraction Fraction::operator-(const Fraction &fr){
	Fraction t;
	t.numer=numer*fr.denom - fr.numer*denom;
	t.denom=denom*fr.denom;
	return t;
}

Fraction Fraction::operator/(const Fraction &fr){
	Fraction t;
	t.numer=numer*fr.denom;
	t.denom=denom*fr.numer;
	return t;
}

void Fraction::reduce_fraction(int n,int d){
	int gcd=find_gcd(n,d);
	numer/=gcd;
	denom/=gcd;
}

void Fraction::print_fraction(){
	reduce_fraction(numer,denom);
	if(denom<0){
		denom=-denom;
		numer=-numer;
	}
	if(denom==1)
		printf("%d\n",numer);
	else
		printf("%d/%d\n",numer,denom);
}

int main(void){
	Fraction f1,f2(2,3);
	printf("f1=");
	f1.print_fraction();
	printf("f2=");
	f2.print_fraction();
	
	printf("Get f1\n");
	f1.setNum(f1.getNum());
	f1.setDen(f1.getDen());
	printf("f1=");
	f1.print_fraction();
	
	Fraction f3=f1+f2,f4=f1*f2,f5=f1-f2,f6=f1/f2;
	printf("f1+f2=");
	f3.print_fraction();
	printf("f1*f2=");
	f4.print_fraction();
	printf("f1-f2=");
	f5.print_fraction();
	printf("f1/f2=");
	f6.print_fraction();
	printf("f1+1=");
	f1.increment();
	f1.print_fraction();
	
	return 0;
}
