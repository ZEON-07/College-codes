#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Queue
{
    struct Node *nodes[100];
    int front, rear;
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = -1;
}

int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

void enqueue(struct Queue *q, struct Node *node)
{
    if (q->rear == 99)
        return;
    if (q->front == -1)
        q->front = 0;
    q->nodes[++q->rear] = node;
}

struct Node *dequeue(struct Queue *q)
{
    if (isEmpty(q))
        return NULL;
    struct Node *temp = q->nodes[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return temp;
}

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    struct Node *newNode = createNode(value);
    if (root == NULL)
        return newNode;
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q))
    {
        struct Node *temp = dequeue(&q);
        if (temp->left == NULL)
        {
            temp->left = newNode;
            break;
        }
        else
        {
            enqueue(&q, temp->left);
        }
        if (temp->right == NULL)
        {
            temp->right = newNode;
            break;
        }
        else
        {
            enqueue(&q, temp->right);
        }
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int value)
{
    if (root == NULL)
        return NULL;
    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);
    struct Node *target = NULL;
    struct Node *temp;
    while (!isEmpty(&q))
    {
        temp = dequeue(&q);
        if (temp->data == value)
            target = temp;
        if (temp->left)
            enqueue(&q, temp->left);
        if (temp->right)
            enqueue(&q, temp->right);
    }
    if (target != NULL)
    {
        int x = temp->data;
        root = deleteNode(root, temp->data);
        target->data = x;
    }
    return root;
}

void printTree(struct Node *root, int space)
{
    if (root == NULL)
        return;
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main()
{
    struct Node *root = NULL;
    int choice, value;
    do
    {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display Tree\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 3:
            printf("\nBinary Tree (rotated):\n");
            printTree(root, 0);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }while(choice != 4);
    return 0;
}
