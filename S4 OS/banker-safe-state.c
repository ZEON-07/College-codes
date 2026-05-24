#include <stdio.h>

int main()
{
    int n = 5, m = 3;

    int alloc[5][3] =
    {
        {0,1,0},
        {2,0,0},
        {3,0,2},
        {2,1,1},
        {0,0,2}
    };

    int max[n][3] =
    {
        {7,5,3},
        {3,2,2},
        {9,0,2},
        {2,2,2},
        {4,3,3}
    };

    int avail[3] = {3,3,2};
    int need[5][3];
    int finish[5] = {0};
    int safeSeq[5];
    int work[3];

    int i, j, k;

    // Copy available to work
    for(i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }

    // Calculate need matrix
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int count = 0;

    while(count < n)
    {
        int safe = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        break;
                    }
                }

                // Process can execute
                if(j == m)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += alloc[i][k];
                    }

                    safeSeq[count] = i;
                    count++;

                    finish[i] = 1;

                    safe = 1;
                }
            }
        }

        // No process could execute
        if(safe == 0)
        {
            printf("\nSYSTEM IS IN UNSAFE STATE\n");
            return 0;
        }
    }

    printf("\nSYSTEM IS IN SAFE STATE\n");

    printf("Safe Sequence: ");

    for(i = 0; i < n; i++)
    {
        printf("P%d ", safeSeq[i]);
    }

    return 0;
}