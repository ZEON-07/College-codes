#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *front = NULL, *rear = NULL;
    struct node *top = NULL;
    struct node *temp;
    int n, val, i;

    printf("Enter number of elements in the queue: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;

        if (rear == NULL)
            front = rear = newnode;
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }

    printf("\nOriginal Queue: ");
    temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    while (front != NULL)
    {
        val = front->data;
        temp = front;
        front = front->next;
        free(temp);

        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = top;
        top = newnode;

        if (front == NULL)
            rear = NULL;
    }

    while (top != NULL)
    {
        val = top->data;
        temp = top;
        top = top->next;
        free(temp);

        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;

        if (rear == NULL)
            front = rear = newnode;
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
    }

    printf("\nReversed Queue: ");
    temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
    return 0;
}
