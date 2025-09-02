#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void enqueue();
void dequeue();

struct node
{
    int data;
    struct node *link;
} *front = NULL, *rear = NULL;

int main()
{
    int choice;

    do
    {
        printf("\nMENU\n");
        printf("1: Create\n2: Enqueue\n3: Dequeue\n4: Display\n5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            enqueue();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct node *temp = front;
    printf("Queue: ");
    while (temp != NULL)
    {
        printf(" | %d |", temp->data);
        if (temp->link != NULL) printf(" -> ");
        temp = temp->link;
    }
    printf(" -> NULL\n");
}

void create()
{
    int e, i;
    struct node *temp;

    while (front != NULL)
    {
        temp = front;
        front = front->link;
        free(temp);
        temp = NULL; 
    }
    rear = NULL;

    printf("\nNo of elements: ");
    scanf("%d", &e);

    for (i = 0; i < e; i++)
    {
        struct node *ptr = malloc(sizeof(struct node));
        if (ptr == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter Data: ");
        scanf("%d", &ptr->data);
        ptr->link = NULL;

        if (rear == NULL)
        {
            front = ptr;
            rear = ptr;
        }
        else
        {
            rear->link = ptr;
            rear = ptr;
        }
    }
}

void enqueue()
{
    struct node *ptr = malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter Data: ");
    scanf("%d", &ptr->data);
    ptr->link = NULL;

    if (rear == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->link = ptr;
        rear = ptr;
    }
    printf("%d enqueued.\n", ptr->data);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct node *temp = front;
    printf("Dequeued: %d\n", temp->data);
    front = front->link;

    if (front == NULL)
    { 
        rear = NULL;
    }
    free(temp);
}
