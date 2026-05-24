#include <stdio.h>

struct process
{
    int pid, at, bt, ct, tat, wt;
} p[20], temp;

int main()
{
    int n, i, j;
    float avgtat = 0, avgwt = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        p[i].pid = i+1;

        printf("\nEnter Arrival Time for P%d: ",i+1);
        scanf("%d",&p[i].at);

        printf("Enter Burst Time for P%d: ",i+1);
        scanf("%d",&p[i].bt);
    }

    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].at > p[j].at)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].ct = p[0].at + p[0].bt;

    for(i=1;i<n;i++)
    {
        if(p[i].at > p[i-1].ct)
            p[i].ct = p[i].at + p[i].bt;
        else
            p[i].ct = p[i-1].ct + p[i].bt;
    }

    for(i=0;i<n;i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        avgtat += p[i].tat;
        avgwt += p[i].wt;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f",avgtat/n);
    printf("\nAverage Waiting Time = %.2f",avgwt/n);

    return 0;
}