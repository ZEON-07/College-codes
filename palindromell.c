#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *prev;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *tail = NULL, *newnode;
    char str[100];
    int i, len;

    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = str[i];
        newnode->next = NULL;
        newnode->prev = NULL;

        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    struct node *left = head;
    struct node *right = tail;
    int flag = 1;

    while (left != NULL && right != NULL && left != right && right->next != left)
    {
        if (left->data != right->data)
        {
            flag = 0;
            break;
        }
        left = left->next;
        right = right->prev;
    }

    if (flag == 1)
        printf("The string '%s' is a palindrome.\n", str);
    else
        printf("The string '%s' is NOT a palindrome.\n", str);

    return 0;
}
