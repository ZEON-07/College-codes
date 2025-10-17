#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp = NULL, *newnode;
    char str[100], ch;
    int count = 0, i;

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = str[i];
        newnode->next = NULL;

        if (head == NULL)
            head = newnode;
        else
            temp->next = newnode;

        temp = newnode;
    }

    printf("Linked List: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Enter character to find occurrences: ");
    scanf(" %c", &ch);

    temp = head;
    while (temp != NULL)
    {
        if (temp->data == ch)
            count++;
        temp = temp->next;
    }

    printf("Character '%c' occurs %d time(s).\n", ch, count);

    return 0;
}
