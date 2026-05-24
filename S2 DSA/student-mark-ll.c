#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int roll_no;
    char name[50];
    int marks;
    struct Student *next;
};

int main()
{
    struct Student *head = NULL, *temp = NULL, *newNode = NULL;
    int sum = 0, highest = -1, lowest = 101;
    float average;

    for (int i = 0; i < 10; i++)
    {
        newNode = (struct Student *)malloc(sizeof(struct Student));
        printf("Enter roll no: ");
        scanf("%d", &newNode->roll_no);
        printf("Enter name: ");
        scanf("%s", newNode->name);
        printf("Enter marks: ");
        scanf("%d", &newNode->marks);

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

        sum += newNode->marks;
        if (newNode->marks > highest)
            highest = newNode->marks;
        if (newNode->marks < lowest)
            lowest = newNode->marks;
    }

    average = sum / 10.0;

    printf("\nAverage Marks: %.2f", average);
    printf("\nHighest Marks: %d", highest);
    printf("\nLowest Marks: %d\n", lowest);

    temp = head;
    printf("\nStudent Details:\n");
    while (temp != NULL)
    {
        printf("Roll: %d, Name: %s, Marks: %d\n", temp->roll_no, temp->name, temp->marks);
        temp = temp->next;
    }

    return 0;
}
