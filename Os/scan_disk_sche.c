#include <stdio.h>  
#include <stdlib.h>  

int main()  
{  
    int rq[100], i, j, n, thm = 0, initial, size, move;  
    printf("Enter no. of request: ");  
    scanf("%d", &n);  

    printf("Enter the request sequences: ");  
    for(i = 0; i < n; i++)  
        scanf("%d", &rq[i]);  

    printf("Enter initial head position: ");  
    scanf("%d", &initial);  

    printf("Enter total disc size: ");  
    scanf("%d", &size);  

    printf("Enter head movement direction for high 1 and for low 0: ");  
    scanf("%d", &move);  

      
    for(i = 0; i < n; i++)  
    {  
        for(j = 0; j < n - i - 1; j++)  
        {  
            if(rq[j] > rq[j+1])  
            {  
                int temp = rq[j];  
                rq[j] = rq[j+1];  
                rq[j+1] = temp;  
            }  
        }  
    }  

    int index = -1;  
    for(i = 0; i < n; i++)  
    {  
        if(initial < rq[i])  
        {  
            index = i;  
            break;  
        }  
    }  

    if(move == 1)  
    {  
        for(i = index; i < n; i++)  
        {  
            thm += abs(rq[i] - initial);  
            initial = rq[i];  
        }  
        thm += abs((size - 1) - initial);  
        initial = size - 1;  
        for(i = index - 1; i >= 0; i--)  
        {  
            thm += abs(rq[i] - initial);  
            initial = rq[i];  
        }  
    }  
    else 
    {  
        for(i = index - 1; i >= 0; i--)  
        {  
            thm += abs(rq[i] - initial);  
            initial = rq[i];  
        }  
        thm += abs(initial - 0);  
        initial = 0;  
        for(i = index; i < n; i++)  
        {  
            thm += abs(rq[i] - initial);  
            initial = rq[i];  
        }  
    }  

    printf("Total head movement is %d\n", thm);  
    return 0;  
}
