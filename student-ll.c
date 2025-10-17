#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int no;
    char name[20];
    float mark;
    struct node *next;
};
struct node *head = NULL;

void insert()
{
    struct node *newnode = malloc(sizeof(struct node)), *temp = head;
    printf("No Name Mark: ");
    scanf("%d %s %f", &newnode->no, newnode->name, &newnode->mark);
    newnode->next = NULL;
    if (!head)
        head = newnode;
    else
    {
        while (temp->next)
            temp = temp->next;
        temp->next = newnode;
    }
}
void del(int n)
{
    struct node *t = head, *p = NULL;
    while (t && t->no != n)
    {
        p = t;
        t = t->next;
    }
    if (!t)
        printf("Not found\n");
    else
    {
        if (!p)
            head = head->next;
        else
            p->next = t->next;
        free(t);
    }
}
void search(int n)
{
    struct node *t = head;
    while (t)
    {
        if (t->no == n)
        {
            printf("%d %s %.2f\n", t->no, t->name, t->mark);
            return;
        }
        t = t->next;
    }
    printf("Not found\n");
}
void display()
{
    struct node *t = head;
    while (t)
    {
        printf("%d %s %.2f\n", t->no, t->name, t->mark);
        t = t->next;
    }
}

int main()
{
    int ch, n;
    while (1)
    {
        printf("\n1.Insert 2.Delete 3.Search 4.Display 5.Exit\n");
        scanf("%d", &ch);
        if (ch == 1)
            insert();
        else if (ch == 2)
        {
            printf("Enter no: ");
            scanf("%d", &n);
            del(n);
        }
        else if (ch == 3)
        {
            printf("Enter no: ");
            scanf("%d", &n);
            search(n);
        }
        else if (ch == 4)
            display();
        else
            break;
    }
}
