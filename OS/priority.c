#include <stdio.h>

struct Process {
    int id, Bt, Pr, Wt, TAt;
} P[20], temp;

int main() {
    int i, j, n; float awt,atat;

    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter process id, burst time, and priority of P-%d: ", i + 1);
        scanf("%d %d %d", &P[i].id, &P[i].Bt, &P[i].Pr);
    }

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(P[j].Pr > P[j+1].Pr) {
                temp = P[j];
                P[j] = P[j+1];
                P[j+1] = temp;
            }
        }
    }

    P[0].Wt = 0;
    P[0].TAt = P[0].Bt;
    awt=P[0].Wt;
    atat=P[0].TAt;

    for(i = 1; i < n; i++) {
        P[i].Wt = P[i-1].TAt;
        P[i].TAt = P[i].Bt + P[i].Wt;
	awt=awt+P[i].Wt;
	atat=atat+P[i].TAt;
    }

    printf("\nPROCESS ID\tBURST TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", P[i].id, P[i].Bt, P[i].Pr, P[i].Wt, P[i].TAt);
    }

   printf ("\n Average Waiting time : %f",awt/n);
   printf ("\n Average Turn Around Time: %f",atat/n);
   printf ("\n");
       printf(" | ");
    for (i = 0; i < n; i++) {
        printf("P%d | ", P[i].id);
    }
    printf("\n");

    printf(" 0    ");
    for (i = 0; i < n; i++) {
        printf("%d    ", P[i].TAt);
    }
    printf("\n");

    return 0;
}
