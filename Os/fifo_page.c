#include<stdio.h>

int main()  
{  
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n, flag;

    printf("Enter the length of reference string: ");  
    scanf("%d", &n);  

    printf("Enter reference string: ");  
    for(i = 0; i < n; i++)  
        scanf("%d", &rs[i]);  

    printf("Enter number of frames: ");  
    scanf("%d", &f);  

    for(i = 0; i < f; i++)  
        m[i] = -1;  // initialize all frames as empty

    printf("\nThe page replacement process is:\n");  

    for(i = 0; i < n; i++)  
    {  
        flag = 0;

        for(k = 0; k < f; k++)  
        {  
            if(m[k] == rs[i])  
            {  
                flag = 1;  
                break;  
            }  
        }  

        if(flag == 0)  // page fault
        {  
            m[count] = rs[i];  
            count = (count + 1) % f;  
            pf++;  
        }  

        for(j = 0; j < f; j++)  
            printf("\t%d", m[j]);  

        if(flag == 0)  
            printf("\tPF No: %d", pf);  

        printf("\n");  
    }  

    printf("\nTotal number of page faults using FIFO: %d\n", pf);  

    return 0;
}
