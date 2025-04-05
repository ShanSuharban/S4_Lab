#include<stdio.h>

int main()
{
    int no_of_process, no_of_blocks;
    int block[10], process[10], allocation[10], blockNum[10];
    int i, j, worstindex = -1;

    printf("Enter the number of blocks: ");
    scanf("%d", &no_of_blocks);

    printf("Enter the size of blocks: ");
    for(i = 0; i < no_of_blocks; i++)
        scanf("%d", &block[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &no_of_process);

    printf("Enter the size of processes: ");
    for(i = 0; i < no_of_process; i++) {
        scanf("%d", &process[i]);
        allocation[i] = -1;
        blockNum[i] = -1;
    }

    for(i = 0; i < no_of_process; i++) {
        worstindex = -1;
        for(j = 0; j < no_of_blocks; j++) {
            if(block[j] >= process[i]) {
                if(worstindex == -1 || block[j] > block[worstindex])
                    worstindex = j;
            }
        }

        if(worstindex != -1) {
            allocation[i] = block[worstindex];
            blockNum[i] = worstindex + 1;
            block[worstindex] -= process[i];
        }
    }

    printf("After allocation:\n");
    printf("Process no\tProcess size\tBlock size\n");
    for(i = 0; i < no_of_process; i++) {
        if(allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, process[i], allocation[i]);
        else
            printf("%d\t\t%d\t\tCan't be allocated\n", i + 1, process[i]);

        // printf("%d\t\t%d\t\tBlock %d\n", i + 1, process[i], blockNum[i]);
    }

    return 0;
}
