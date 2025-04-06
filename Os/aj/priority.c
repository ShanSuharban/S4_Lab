#include <stdio.h>

void main() {
    int n, i, j, smallest, temp;

    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    int pid[n], bt[n], prio[n];

    printf("Enter the Process IDs:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &pid[i]);
    }

    for (i = 0; i < n; i++) {
        printf("Enter the priority for process with ID %d:\n", pid[i]);
        scanf("%d", &prio[i]);
    }

    for (i = 0; i < n; i++) {
        printf("Enter the burst time for process with ID %d:\n", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Sorting based on priority (lower value = higher priority)
    for (i = 0; i < n; i++) {
        smallest = i;
        for (j = i + 1; j < n; j++) {
            if (prio[j] < prio[smallest]) {
                smallest = j;
            }
        }

        // Swap priority
        temp = prio[i];
        prio[i] = prio[smallest];
        prio[smallest] = temp;

        // Swap burst time
        temp = bt[i];
        bt[i] = bt[smallest];
        bt[smallest] = temp;

        // Swap process ID
        temp = pid[i];
        pid[i] = pid[smallest];
        pid[smallest] = temp;
    }

    // Calculate Waiting Time
    int wt[n];
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    // Calculate Turnaround Time
    int tat[n];
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    float avgWT = 0, avgTAT = 0;
    for (i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    // Output
    printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], prio[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWT);
    printf("Average Turnaround Time: %.2f\n", avgTAT);
}
