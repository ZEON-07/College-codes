#include <stdio.h>
int main()
{
    int a[100], n, item, i;
    printf("enter size : ");
    scanf("%d", &n);
    printf("Enter elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter item :");
    scanf("%d", &item);
    for (i = 0; i < n; i++)
    {
        if (item == a[i])
        {
            printf("item found at %d", i);
            break;
        }
    }
    if (i == n)
    {
        printf("item not found");
    }
    return 0;
}