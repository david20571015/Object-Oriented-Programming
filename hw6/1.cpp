#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
    //text

    srand(time(NULL));

    FILE *fp1, *fp2;
    fp1 = fopen("t1.txt", "w");
    for (int i = 0; i < 200; i++)
        fprintf(fp1, "%d\n", rand());

    rewind(fp1);
    int num1[200], t1;
    fp1 = fopen("t1.txt", "r");
    for (int i = 0; i < 200; i++)
        fscanf(fp1, "%d", &num1[i]);

    for (int i = 0; i < 199; i++)
        for (int j = i + 1; j < 200; j++)
            if (num1[i] < num1[j])
            {
                t1 = num1[i];
                num1[i] = num1[j];
                num1[j] = t1;
            }

    fp2 = fopen("t2.txt", "w");
    for (int i = 0; i < 200; i++)
        fprintf(fp2, "%d\n", num1[i]);

    rewind(fp2);
    fp1 = fopen("t1.txt", "a");
    fp2 = fopen("t2.txt", "r");
    for (int i = 0; i < 200; i++)
    {
        fscanf(fp2, "%d", &t1);
        fprintf(fp1, "%d\n", t1);
    }

    fclose(fp1);
    fclose(fp2);

    //binary

    srand(time(NULL));

    FILE *fp3, *fp4;
    fp3 = fopen("t3.dat", "wb");
    for (int i = 0; i < 200; i++)
    {
        int k = rand();
        fwrite(&k, sizeof(int), 1, fp3);
    }

    rewind(fp3);
    int num2[200], t2;
    fp3 = fopen("t3.dat", "rb");
    for (int i = 0; i < 200; i++)
        fread(&num2[i], sizeof(int), 1, fp3);

    for (int i = 0; i < 199; i++)
        for (int j = i + 1; j < 200; j++)
            if (num2[i] < num2[j])
            {
                t2 = num2[i];
                num2[i] = num2[j];
                num2[j] = t2;
            }

    fp4 = fopen("t4.dat", "wb");
    for (int i = 0; i < 200; i++)
        fwrite(&num2[i], sizeof(int), 1, fp4);

    rewind(fp4);
    fp3 = fopen("t3.dat", "ab");
    fp4 = fopen("t4.dat", "rb");
    for (int i = 0; i < 200; i++)
    {
        fread(&t2, sizeof(int), 1, fp3);
        fwrite(&t2, sizeof(int), 1, fp4);
    }

    fclose(fp3);
    fclose(fp4);

    //getch();
    return 0;
}