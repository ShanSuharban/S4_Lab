#include <stdio.h>

int main() {
    int n, at[10], bt[10], ct[10], wt[10], tat[10], sum, i, j, k;
    float totaltat = 0, totalwt = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("Enter the process Arrival time and Burst time\n");
    for (i = 0; i < n; i++) {
        printf("Enter Arrival time of process [%d] : ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst time of process [%d] : ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate the completion time of processes.
    sum = at[0];
    for (j = 0; j < n; j++) {
        sum += bt[j];
        ct[j] = sum;
    }

    // Calculate the turn around time.
    for (k = 0; k < n; k++) {
        tat[k] = ct[k] - at[k];
        totaltat += tat[k];
    }

    // Calculate the waiting time.
    for (k = 0; k < n; k++) {
        wt[k] = tat[k] - bt[k];
        totalwt += wt[k];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time : %f", totaltat / n);
    printf("\nAverage Waiting Time    : %f\n", totalwt / n);

    return 0;
}
