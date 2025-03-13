#include<stdio.h>

int main(){
int at[20],at2[20],bt[20],ex[20],seq[20],re[20],wt[20],tat[20];
int n,i,j,start,pos,max=0,min,idle=0,k=0;
float av1=0,av2 = 0;
    printf("****FCFS Scheduling****\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter arrival time of process P%d: ", i);
        scanf("%d", &at[i]);
        at2[i] = at[i];
        
        printf("Enter burst time of process P%d: ", i);
        scanf("%d", &bt[i]);
    }
    
    printf("Process   Arrival-time(s)   Burst-time(s)\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\n", i, at[i], bt[i]);
    }

    start = at[0];
    for(i = 1; i < n; i++) {
        if(start > at[i]) {
            start = at[i];
        }
    }

    printf("*****OUTPUT*****\n");
    printf("Sequence of execution (Gantt chart)\n");
    
    for(i = 0; i < n; i++) {
        if(max < at[i]) {
            max = at[i];
        }
    }
    
    max = max + 1;
    printf("   ");
    for(i = 0; i < n; i++) {
        min = max;
        for(j = 0; j < n; j++) {
            if(at[j] != -1) {
                if(at[j] < min) {
                    min = at[j];
                    pos = j;
                }
            }
        }
        
        printf("P%d\t", pos);
        seq[k++] = pos;

        if(start < at[pos]) {
            idle += at[pos] - start;
            start = at[pos];
        }
        
        re[pos] = start;
        start = start + bt[pos];
        at[pos] = -1;
        ex[pos] = start;
    }
    
    printf("\n");

    for(i = 0; i < n; i++) {
        printf("%d\t", ex[seq[i]]);
    }

    printf("\n");

    printf("Process   Arrival-time(s)   Burst-time(s)   Completion-time(s)   Waiting-time(s)   Turnaround-time(s)\n");

    for(i = 0; i < n; i++) {
        tat[i] = ex[i] - at2[i];
        wt[i] = tat[i] - bt[i];
        av1 += wt[i];
        av2 += tat[i];

        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, at2[i], bt[i], ex[i], wt[i], tat[i]);
    }

    printf("Average waiting time(s): %f\n", av1 / n);
    printf("Average turnaround time(s): %f\n", av2 / n);
    printf("CPU idle time(s): %d\n", idle);

    return 0;
}
