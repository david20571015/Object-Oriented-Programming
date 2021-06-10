#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    Stack *next;
};

void push(Stack **s, int n)
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->data = n;
    p->next = *s;
    *s = p;
}

void pop(Stack **s)
{
    Stack *p = (*s)->next;
    free(*s);
    *s = p;
}

void display(Stack *s)
{
    while (s != NULL)
    {
        printf("%d\n", s->data);
        s = s->next;
    }
}

int main()
{
    Stack *head = NULL;

    int f;
    char conti;

    do
    {
        system("cls");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &f);

        switch (f)
        {
        case 1:
            int n;
            scanf("%d", &n);
            push(&head, n);
            break;
        case 2:
            pop(&head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(1);
            break;
        }

        printf("continue? (y/n) ");
        scanf(" %c", &conti);
    } while (conti == 'y');

    getchar();
    return 0;
}