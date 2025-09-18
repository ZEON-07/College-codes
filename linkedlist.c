#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insert();
void delete();

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
        printf("\nMENU\n1: Create\n2: Insert\n3: Delete\n4: Display\n5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete();
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

void insert()
{
    int choice;
    printf("\n1: Insert as first node\n2: Insert as last node\n3: Insert at intermediate\n");
    scanf("%d", &choice);

    struct node *ptr, *temp;
    switch (choice)
    {
    case 1:
        ptr = malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &ptr->data);
        ptr->link = head->link;
        head->link = ptr;
        break;
    case 2:
        temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        ptr = malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d", &ptr->data);
        ptr->link = NULL;
        temp->link = ptr;
        break;
    case 3:
    {
        int key;
        printf("Enter the data after which you want to insert: ");
        scanf("%d", &key);
        temp = head->link;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->link;
        }
        if (temp == NULL)
        {
            printf("Node with data %d not found.\n", key);
        }
        else
        {
            ptr = malloc(sizeof(struct node));
            printf("Enter Data: ");
            scanf("%d", &ptr->data);
            ptr->link = temp->link;
            temp->link = ptr;
        }
        break;
    }
    default:
        printf("Invalid choice.\n");
    }
}

void delete()
{
    if (head->link == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    int choice;
    printf("\n1: Delete first node\n2: Delete last node\n3: Delete specific node\n");
    scanf("%d", &choice);

    struct node *temp = head->link, *prev = head;

    switch (choice)
    {
    case 1:
        head->link = temp->link;
        free(temp);
        printf("First node deleted.\n");
        break;
    case 2:
        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        free(temp);
        printf("Last node deleted.\n");
        break;
    case 3:
    {
        int key;
        printf("Enter the data to delete: ");
        scanf("%d", &key);
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->link;
        }
        if (temp == NULL)
        {
            printf("Node with data %d not found.\n", key);
        }
        else
        {
            prev->link = temp->link;
            free(temp);
            printf("Node deleted.\n");
        }
        break;
    }
    default:
        printf("Invalid choice.\n");
    }
}
