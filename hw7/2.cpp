#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    node *next;
};

int min(node *h)
{
    int m = h->data;
    while (h != NULL)
    {
        if (h->data < m)
            m = h->data;
        h = h->next;
    }
    return m;
}

void traverse(node *h)
{
    node *p;
    while (h->next != NULL)
    {
        if (h->next->data < 0)
        {
            p = h->next;
            h->next = h->next->next;
            free(p);
        }
        else
            h = h->next;        
    }
}

int main()
{
    int n;
    node *head, *tail, *p;
    head = tail = (node *)malloc(sizeof(node));
    while (scanf("%d", &n) != EOF)
    {
        p = (node *)malloc(sizeof(node));
        p->data = n;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }

    printf("min = %d\n",min(head->next));
    traverse(head->next);

    node *s = head->next;
    while (s != NULL)
    {
        printf("%d\n", s->data);
        s = s->next;
    }

    getchar();
    return 0;
}