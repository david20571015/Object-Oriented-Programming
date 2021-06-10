#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe, pow;
    node *next;
};

int main()
{
    node *p1 = NULL, *p2 = NULL, *p3 = NULL, *p;
    int coeff, power;

    while (scanf("%d %d", &coeff, &power) != EOF)
    {
        p = (node *)malloc(sizeof(node));
        p->coe = coeff;
        p->pow = power;
        p->next = p1;
        p1 = p;
    }

    while (scanf("%d %d", &coeff, &power) != EOF)
    {
        p = (node *)malloc(sizeof(node));
        p->coe = coeff;
        p->pow = power;
        p->next = p2;
        p2 = p;
    }

    node *h1 = p1, *h2 = p2;
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->pow > h2->pow)
        {
            p = (node *)malloc(sizeof(node));
            p->coe = h1->coe;
            p->pow = h1->pow;
            p->next = p3;
            p3 = p;
            h1 = h1->next;
        }
        else if (h1->pow < h2->pow)
        {
            p = (node *)malloc(sizeof(node));
            p->coe = h2->coe;
            p->pow = h2->pow;
            p->next = p3;
            p3 = p;
            h2 = h2->next;
        }
        else if (h1->pow == h2->pow)
        {
            p = (node *)malloc(sizeof(node));
            p->coe = h1->coe + h2->coe;
            p->pow = h1->pow;
            p->next = p3;
            p3 = p;
            h1 = h2->next;
            h2 = h2->next;
        }
    }

    s = p3;
    while (s != NULL)
    {
        printf("%d x^%d + ", s->coe, s->pow);
        s = s->next;
    }

    getchar();
    return 0;
}