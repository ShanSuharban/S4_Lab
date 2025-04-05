#include <stdio.h>

int main() {
    int nb, np;
    int b[10], p[10], a[10], blockNum[10];
    int i, j;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter the size of each block:\n");
    for(i = 0; i < nb; i++) {
        scanf("%d", &b[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &np);

    printf("Enter the size of each process:\n");
    for(i = 0; i < np; i++) {
        scanf("%d", &p[i]);
        a[i] = -1;
        blockNum[i] = -1;
    }

    for(i = 0; i < np; i++) {
        for(j = 0; j < nb; j++) {
            if(b[j] >= p[i]) {
                a[i] = b[j];
                blockNum[i] = j + 1;
                b[j] -= p[i];
                break;
            }
        }
    }

    printf("\nAfter allocation:\n");
    printf("Process No\tProcess Size\tBlock Size\n");
    for(i = 0; i < np; i++) {
        if(a[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i+1, p[i], a[i]);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, p[i]);

        // printf("%d\t\t%d\t\tBlock %d\n", i+1, p[i], blockNum[i]);
    }

    return 0;
}
