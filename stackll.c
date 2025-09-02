#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void push();
void pop();

struct node
{
    int data;
    struct node *link;
} *head = NULL;

int main()
{
    int choice;
    head = (struct node *)malloc(sizeof(struct node));
    head->link = NULL;

    do
    {
        printf("\nMENU\n1: Create\n2: Push\n3: Pop\n4: Display\n5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
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
    if (head->link == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head->link;
    while (temp != NULL)
    {
        printf("| %d | --> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void create()
{
    int e;
    printf("\nNo of elements: ");
    scanf("%d", &e);

    struct node *temp = head;
    for (int i = 0; i < e; i++)
    {
        struct node *ptr = malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &ptr->data);
        ptr->link = NULL;
        temp->link = ptr;
        temp = temp->link;
    }
}

void push()
{
    struct node *ptr, *temp;
    ptr = malloc(sizeof(struct node));
    printf("Enter Data: ");
    scanf("%d", &ptr->data);
    ptr->link = head->link;
    head->link = ptr;
}

void pop()
{
    if (head->link == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head->link, *prev = head;
    head->link = temp->link;
    free(temp);
    printf("First node deleted.\n");
}
