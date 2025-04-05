#include <stdio.h>

int main() {
    int n, m, i, j, y;
    int alloc[20][20], max[20][20], avail[20];
    int safesequence[20], finish[20], work[20], need[20][20];
    int ind = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the Allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the Max matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the Available resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

 
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("\nNeed Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    
    for (i = 0; i < n; i++) finish[i] = 0;
    for (i = 0; i < m; i++) work[i] = avail[i];

    int completed = 0, safe = 1;
    while (completed < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int can_allocate = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        can_allocate = 0;
                        break;
                    }
                }

                if (can_allocate) {
                    for (y = 0; y < m; y++)
                        work[y] += alloc[i][y];
                    safesequence[ind++] = i;
                    finish[i] = 1;
                    completed++;
                    found = 1;
                }
            }
        }
        if (!found) {
            safe = 0;
            break;
        }
    }

    if (safe) {
        printf("\nSystem is in a safe state.\nSafe Sequence: ");
        for (i = 0; i < n; i++)
            printf("P%d ", safesequence[i]);
        printf("\n");
    } else {
        printf("\nSystem is not in a safe state.\n");
    }

    return 0;
}
