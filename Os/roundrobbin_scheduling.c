#include <stdio.h>

int main() {
    int i, n, time = 0, remain, ts, flag = 0;
    int at[10], bt[10], rt[10];
    int sumwt = 0, sumtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    remain = n;

    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time of process P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter the time slice: ");
    scanf("%d", &ts);

    i = 0;
    while (remain != 0) {
        if (at[i] <= time && rt[i] > 0) {
            if (rt[i] <= ts) {
                time += rt[i];
                rt[i] = 0;
                flag = 1;
            } else {
                rt[i] -= ts;
                time += ts;
            }

            if (rt[i] == 0 && flag == 1) {
                remain--;
                sumwt += time - at[i] - bt[i];
                sumtat += time - at[i];
                flag = 0;
            }
        }

        i++;
        if (i == n) {
            i = 0;
        }
    }

    printf("\nTotal Waiting Time = %d", sumwt);
    printf("\nAverage Waiting Time = %.2f", sumwt * 1.0 / n);
    printf("\nTotal Turnaround Time = %d", sumtat);
    printf("\nAverage Turnaround Time = %.2f\n", sumtat * 1.0 / n);

    return 0;
}
