#include <stdio.h>

struct process
{
    int pid, at, bt, ct, wt, tat, completed;
} p[10];

int main()
{
    int n, i, time = 0, completed = 0;
    int min, pos = -1;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;

        printf("Enter Arrival Time for P%d: ", i + 1);
        scanf("%d", &p[i].at);

        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &p[i].bt);

        p[i].completed = 0;
    }

    while(completed < n)
    {
        min = 9999;
        pos = -1;

        // Find shortest job among arrived processes
        for(i = 0; i < n; i++)
        {
            if(p[i].at <= time &&
               p[i].completed == 0 &&
               p[i].bt < min)
            {
                min = p[i].bt;
                pos = i;
            }
        }

        // If no process has arrived
        if(pos == -1)
        {
            time++;
        }
        else
        {
            // Execute process completely
            time += p[pos].bt;

            p[pos].ct = time;

            p[pos].tat = p[pos].ct - p[pos].at;

            p[pos].wt = p[pos].tat - p[pos].bt;

            p[pos].completed = 1;

            completed++;

            avgwt += p[pos].wt;
            avgtat += p[pos].tat;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].wt,
               p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);

    return 0;
}