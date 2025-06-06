#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, j, n, TotalHeadMovement = 0, initial, size, move;

    printf("Enter the number of requests\n");
    scanf("%d", &n);

    printf("Enter the request sequence\n");
    for(i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position\n");
    scanf("%d", &initial);

    printf("Enter total disk size\n");
    scanf("%d", &size);

    printf("Enter head movement direction for high (1) and for low (0)\n");
    scanf("%d", &move);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    int index;
    for(i = 0; i < n; i++) {
        if(initial < RQ[i]) {
            index = i;
            break;
        }
    }

    if(move == 1) {
        for(i = index; i < n; i++) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMovement += abs((size - 1) - initial);
        initial = 0;
        TotalHeadMovement += (size - 1);
        for(i = 0; i < index; i++) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else {
        for(i = index - 1; i >= 0; i--) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMovement += abs(initial - 0);
        initial = size - 1;
        TotalHeadMovement += (size - 1);
        for(i = n - 1; i >= index; i--) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    printf("Total Head Movement = %d\n", TotalHeadMovement);
    return 0;
}
