#include <stdio.h>

int main() {
    int n, m, i, j, k, y;
    int alloc[20][20], max[20][20], avail[50], ind = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    printf("Enter the number of Resources: ");
    scanf("%d", &m);

    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the Max Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Available Resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    int finish[n], safesequence[n], work[m], need[n][m];

    // Calculating NEED matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("NEED Matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf(" %d ", need[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    safesequence[ind++] = i;
                    for (y = 0; y < m; y++) {
                        work[y] += alloc[i][y];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    printf("\nFollowing is the SAFE Sequence:\n");
    for (i = 0; i < n; i++) {
        printf(" P%d ", safesequence[i]);
    }

    return 0;
}
