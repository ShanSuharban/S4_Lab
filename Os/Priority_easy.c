#include <stdio.h>

int main() {
    int n, i, t = 0, done = 0;
    int at[20], bt[20], rt[20], pr[20];     // Arrival Time, Burst Time, Remaining Time, Priority
    int ct[20], tat[20], wt[20];            // Completion Time, Turnaround Time, Waiting Time
    float sumTAT = 0, sumWT = 0;

    // Input: number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input: AT, BT, Priority for each process
    for (i = 0; i < n; i++) {
        printf("AT, BT, Priority of P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i]; // Initialize remaining time
    }

    // Preemptive Priority Scheduling Simulation
    while (done < n) {
        int min = 1e9, index = -1;

        // Find process with highest priority that's ready to execute
        for (i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && pr[i] < min) {
                min = pr[i];
                index = i;
            }
        }

        // If a process is selected, execute it for 1 unit of time
        if (index != -1) {
            rt[index]--;

            // If process completes
            if (rt[index] == 0) {
                ct[index] = t + 1;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];
                sumTAT += tat[index];
                sumWT += wt[index];
                done++;
            }
        }

        t++; // Move time forward
    }

    // Output results
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Print averages
    printf("\nAvg TAT: %.2f  Avg WT: %.2f\n", sumTAT / n, sumWT / n);

    return 0;
}
