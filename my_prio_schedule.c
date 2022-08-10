#include <stdio.h>

void main()
{
    int pr[20], p[20], wt[20], bt[20], tat[20], i, j, n, pos, temp, total = 0, avg_wt, avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter Priority and Burst Time: \n");
    for (i = 0; i < n; i++)
    {
        printf("Process[%d]: \n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }

    // Sorting according to priority
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;

        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }

    // Calculating wait time

    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
        total += wt[i];
    }
    avg_wt = total / n;
    total = 0;

    printf("Process \t Burst Time \t Waiting Time \t Turnaround Time \n");
    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        total += tat[i];
        printf("P[%d] \t\t %d \t\t %d \t\t %d \n", p[i], bt[i], wt[i], tat[i]);
    }
    avg_tat = total / n;
    printf("Average Waiting time: %d \n", avg_wt);
    printf("Average Turnaround Time: %d \n", avg_tat);
}