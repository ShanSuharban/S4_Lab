#include <stdio.h>

struct {
    int AT, WT, BT, TAT, CT, PID, RT;
} P[20], t;

int main() {
    int n, i, min, j, temp, temp2;
    double avg_WT = 0, avg_TAT = 0;

    printf("SJF Scheduling\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("No process exist or negative input.\n");
    } else {
        for (i = 0; i < n; i++) {
            printf("Enter details for process %d:\n", i + 1);
            printf("Arrival Time: ");
            scanf("%d", &P[i].AT);
            printf("Burst Time: ");
            scanf("%d", &P[i].BT);
            P[i].PID = i + 1;
        }

        printf("\nProcess\tArrival Time\tBurst Time\n");
        for (i = 0; i < n; i++) {
            P[i].TAT = P[i].CT - P[i].AT;
            P[i].WT  = P[i].TAT - P[i].BT;
            printf("P%d\t%d\t\t%d\n", P[i].PID, P[i].AT, P[i].BT);
        }

        // Sort based on arrival time
        for (i = 0; i < n; i++) {
            min = i;
            for (j = i + 1; j < n; j++) {
                if (P[j].AT < P[min].AT) {
                    min = j;
                }
            }
            t = P[i];
            P[i] = P[min];
            P[min] = t;
        }

        for (i = 0; i < n; i++) {
            P[i].RT = P[i].BT;
        }

        P[n].RT = 9999;  // Sentinel value for comparison
        j = 0;

        for (min = 0; j != n; min++) {
            temp = n;
            for (i = 0; i < n; i++) {
                if (P[i].AT <= min && P[i].RT < P[temp].RT && P[i].RT > 0) {
                    temp = i;
                }
            }

            P[temp].RT--;

            if (P[temp].RT == 0) {
                j++;
                temp2 = min + 1;
                P[temp].CT = temp2;
            }
        }

        printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
        for (i = 0; i < n; i++) {
            P[i].TAT = P[i].CT - P[i].AT;
            P[i].WT  = P[i].TAT - P[i].BT;

            printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
                   P[i].PID, P[i].AT, P[i].BT, P[i].CT, P[i].TAT, P[i].WT);

            avg_TAT += P[i].TAT;
            avg_WT  += P[i].WT;
        }

        avg_TAT = avg_TAT / n;
        avg_WT  = avg_WT / n;

        printf("\nAverage Turnaround Time = %.2f\n", avg_TAT);
        printf("Average Waiting Time    = %.2f\n", avg_WT);
    }

    return 0;
}
