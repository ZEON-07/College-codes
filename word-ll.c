#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char word[50];
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, i, count = 0;
    char target[50];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter word: ");
        scanf("%s", newNode->word);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    printf("Enter word to find: ");
    scanf("%s", target);

    temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->word, target) == 0)
        {
            count++;
        }
        temp = temp->next;
    }

    printf("The word '%s' occurs %d times\n", target, count);

    return 0;
}
