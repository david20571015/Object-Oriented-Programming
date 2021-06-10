#include <stdio.h>
#include <string.h>
#include <conio.h>

struct telephone
{
    int area;
    int num;
};

struct people
{
    char name[11];
    int sex;
    char edu;
    char major[3];
    char na[4];
    telephone tel;
};

int main()
{
    //text

    people p;

    FILE *fp1;
    fp1 = fopen("personal_material.txt", "r");

    for (int i = 0; i < 12; i++)
    {
        fscanf(fp1, " %s %d %c %s %s %d %d", p.name, &(p.sex), &(p.edu), p.major, p.na, &(p.tel.area), &(p.tel.num));
        if (p.sex == 1 && p.edu == 'B' && strcmp(p.major, "EE") == 0)
            printf("%-10s %d %c %s %s 0%d-%d\n", p.name, p.sex, p.edu, p.major, p.na, p.tel.area, p.tel.num);
    }
    printf("\n");
    
    rewind(fp1);
    for (int i = 0; i < 12; i++)
    {
        fscanf(fp1, " %s %d %c %s %s %d %d", p.name, &(p.sex), &(p.edu), p.major, p.na, &(p.tel.area), &(p.tel.num));
        if (strcmp(p.na, "ROC") == 0 && p.tel.area == 2)
            printf("%-10s %d %c %s %s 0%d-%d\n", p.name, p.sex, p.edu, p.major, p.na, p.tel.area, p.tel.num);
    }
    fclose(fp1);

    getch();
    return 0;
}