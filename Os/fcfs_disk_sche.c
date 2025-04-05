#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, n, totalheadmovement = 0, initial;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    printf("\nSequence of head movement:\n");
    for(i = 0; i < n; i++) {
  //    printf("Head moves from %d to %d => Movement = %d\n", initial, RQ[i], abs(RQ[i] - initial));
        totalheadmovement += abs(RQ[i] - initial);
        initial = RQ[i];
    }

    printf("\nTotal head movement is %d\n", totalheadmovement);

    return 0;
}
