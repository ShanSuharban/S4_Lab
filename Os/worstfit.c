#include <stdio.h>

int main() {
    int np, nb, b[10], p[10], a[10], blockNum[10];
    int i, j, wi;

    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the size of blocks: ");
    for(i = 0; i < nb; i++)
        scanf("%d", &b[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &np);

    printf("Enter the size of processes: ");
    for(i = 0; i < np; i++) {
        scanf("%d", &p[i]);
        a[i] = -1;
        blockNum[i] = -1;
    }

    for(i = 0; i < np; i++) {
        wi = -1;
        for(j = 0; j < nb; j++) {
            if(b[j] >= p[i]) {
                if(wi == -1 || b[j] > b[wi])
                    wi = j;
            }
        }

        if(wi != -1) {
            a[i] = b[wi];
            blockNum[i] = wi + 1;
            b[wi] -= p[i];
        }
    }

    printf("After allocation:\n");
    printf("Process no\tProcess size\tBlock size\n");
    for(i = 0; i < np; i++) {
        if(a[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, p[i], a[i]);
        else
            printf("%d\t\t%d\t\tCan't be allocated\n", i + 1, p[i]);

        // printf("%d\t\t%d\t\tBlock %d\n", i + 1, p[i], blockNum[i]);
    }

    return 0;
}

