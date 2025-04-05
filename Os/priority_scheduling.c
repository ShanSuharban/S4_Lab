#include <stdio.h>

int main() {
    int pn[10], bt[10], at[10], p[10], n;
    int i, j, k, l, temp, t;
    int rt[10], ct[10], wt[10], ta[10];
    int now[10], b = 0;
    int totwt = 0, totta = 0;
    float awt, ata;

    printf("***** Priority Scheduling (Preemptive) *****\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        pn[i] = i + 1;
        printf("\nEnter details for Process %d\n", pn[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        printf("Priority (lower number = higher priority): ");
        scanf("%d", &p[i]);
    }

    printf("\nBefore Scheduling:\n");
    printf("PName\tArrival\tBurst\tPriority\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", pn[i], at[i], bt[i], p[i]);
    }

    t = at[0];
    for (i = 1; i < n; i++) {
        if (t > at[i]) {
            t = at[i];
        }
    }

    for (i = 0; i < n;) {
        b = 0;
        for (j = 0; j < n; j++) {
            if (at[j] <= t && rt[j] > 0) {
                now[b++] = j;
            }
        }

        if (b == 0) {
            t++;
        } else if (b == 1) {
            t++;
            temp = now[0];
            rt[temp]--;
            if (rt[temp] == 0) {
                ct[temp] = t;
                i++;
            }
        } else {
            for (k = 0; k < b - 1; k++) {
                for (l = k + 1; l < b; l++) {
                    if (p[now[k]] > p[now[l]]) {
                        temp = now[k];
                        now[k] = now[l];
                        now[l] = temp;
                    } else if (p[now[k]] == p[now[l]]) {
                        if (pn[now[k]] > pn[now[l]]) {
                            temp = now[k];
                            now[k] = now[l];
                            now[l] = temp;
                        }
                    }
                }
            }

            t++;
            rt[now[0]]--;
            if (rt[now[0]] == 0) {
                ct[now[0]] = t;
                i++;
            }
        }
    }

    printf("\n\nAfter Scheduling:\n");
    printf("PName\tArrival\tBurst\tPriority\tCompletion\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        ta[i] = ct[i] - at[i];
        wt[i] = ta[i] - bt[i];
        totwt += wt[i];
        totta += ta[i];
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n",
               pn[i], at[i], bt[i], p[i], ct[i], wt[i], ta[i]);
    }

    awt = (float)totwt / n;
    ata = (float)totta / n;

    printf("\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f\n", ata);

    return 0;
}
