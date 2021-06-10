#include<stdio.h>
#include<conio.h>
struct student{
    int id;
    char name[10];
    int s1,s2;
};

int merge(FILE *fp1,FILE *fp2,FILE *fp3){
    student s[20],t;
    int i,count=0;
    for(i=0;fscanf(fp1,"%d %s %d %d",&s[i].id,s[i].name,&s[i].s1,&s[i].s2)!=EOF;i++);
    for(i=i;fscanf(fp2,"%d %s %d %d",&s[i].id,s[i].name,&s[i].s1,&s[i].s2)!=EOF;i++);

    for(int j=0;j<i-1;j++)
        for(int k=j+1;k<i;k++)    
            if(s[k].id<s[j].id)
            {
            t=s[k];
            s[k]=s[j];
            s[j]=t;
            }

    for(int j=0;j<i;j++)
    {
        count++;
        fwrite(&s[j],sizeof(student),1,fp3);
        while(s[j].id==s[j+1].id)
            j++;            
    }

    return count;
}

int main(){

    FILE *fp1,*fp2,*fp3;
    fp1=fopen("student1.txt","r");
    fp2=fopen("student2.txt","r");
    fp3=fopen("student3.dat","wb");

    int n=merge(fp1,fp2,fp3);

    rewind(fp3);
    fp3=fopen("student3.dat","rb");

    student t;
    for(int i=0;i<n;i++)
    {
        fread(&t,sizeof(student),1,fp3);
        printf("%d %s %d %d\n",t.id,t.name,t.s1,t.s2);
    }
        
    getch();

    return 0;
}