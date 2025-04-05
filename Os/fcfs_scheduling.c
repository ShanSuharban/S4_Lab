#include <stdio.h>

int main() {
    int n, i, j;
    int at[10], bt[10], ct[10], wt[10], tat[10];
    int temp;
    float totaltat = 0, totalwt = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    
    for (i = 0; i < n; i++) {
        printf("Enter Arrival time of process [%d]: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst time of process [%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    
    int current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < at[i]) {
            current_time = at[i]; 
        }
        ct[i] = current_time + bt[i];
        current_time = ct[i];

        tat[i] = ct[i] - at[i];       
        wt[i] = tat[i] - bt[i];       

        totaltat += tat[i];
        totalwt += wt[i];
    }

    
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", totaltat / n);
    printf("\nAverage Waiting Time: %.2f\n", totalwt / n);

    return 0;
}
