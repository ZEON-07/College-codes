#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff, pow;
    struct node *next;
};

struct node *create()
{
    struct node *head = NULL, *tail = NULL, *newnode;
    int n, c, p;
    printf("No. of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Coeff & Power: ");
        scanf("%d%d", &c, &p);
        newnode = malloc(sizeof(struct node));
        newnode->coeff = c;
        newnode->pow = p;
        newnode->next = NULL;
        if (!head)
            head = tail = newnode;
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}

void display(struct node *poly)
{
    while (poly)
    {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

struct node *add(struct node *p1, struct node *p2)
{
    struct node *res = NULL, *tail = NULL, *newnode;
    while (p1 && p2)
    {
        newnode = malloc(sizeof(struct node));
        if (p1->pow == p2->pow)
        {
            newnode->coeff = p1->coeff + p2->coeff;
            newnode->pow = p1->pow;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            newnode->coeff = p1->coeff;
            newnode->pow = p1->pow;
            p1 = p1->next;
        }
        else
        {
            newnode->coeff = p2->coeff;
            newnode->pow = p2->pow;
            p2 = p2->next;
        }
        newnode->next = NULL;
        if (!res)
            res = tail = newnode;
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    while (p1)
    {
        newnode = malloc(sizeof(struct node));
        *newnode = *p1;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
        p1 = p1->next;
    }
    while (p2)
    {
        newnode = malloc(sizeof(struct node));
        *newnode = *p2;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
        p2 = p2->next;
    }
    return res;
}

int main()
{
    struct node *p1, *p2, *sum;
    printf("Poly 1:\n");
    p1 = create();
    printf("Poly 2:\n");
    p2 = create();
    sum = add(p1, p2);
    printf("\nP1: ");
    display(p1);
    printf("P2: ");
    display(p2);
    printf("Sum: ");
    display(sum);
}
