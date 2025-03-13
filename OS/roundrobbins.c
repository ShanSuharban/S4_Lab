#include <stdio.h>

int main() {
    int i, n, time, remain, flag = 0, ts;
    int sum_wait = 0, sum_turnaround = 0, at[10], bt[10], rt[10];

    printf("Enter no of Processes: ");
    scanf("%d", &n);
    remain = n;

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for Process P%d: ", i + 1);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time slice: ");
    scanf("%d", &ts);

    for (time = 0, i = 0; remain != 0;) {
        if (rt[i] <= ts && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        } else if (rt[i] > 0) {
            rt[i] -= ts;
            time += ts;
        }

        if (rt[i] == 0 && flag == 1) {
            remain--;
            sum_wait += time - at[i] - bt[i];
            sum_turnaround += time - at[i];
            flag = 0;
        }

        if (i == n - 1) {
            i = 0;
        } else if (at[i + 1] <= time) {
            i++;
        } else {
            i = 0;
        }
    }

    printf("\nTotal Waiting time = %d\n", sum_wait);
    printf("Average Waiting time = %.2f\n", (float)sum_wait / n);
    printf("\nTotal Turnaround time = %d\n", sum_turnaround);
    printf("Average Turnaround time = %.2f\n", (float)sum_turnaround / n);

    return 0;
}
