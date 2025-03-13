#include<stdio.h>
int main()
{
        int no_of_process,no_of_blocks,block[10],process[10],allocation[10],i,j,bestindex=-1;
        printf("Enter the number of blocks: ");
        scanf("%d",&no_of_blocks);
        printf("Enter the size of blocks: ");
        for(i=0;i<no_of_blocks;i++)
                scanf("%d",&block[i]);
        printf("Enter the number of process: ");
        scanf("%d",&no_of_process);
        printf("Enter the size of processes: ");
        for(i=0;i<no_of_process;i++)
        {
                scanf("%d",&process[i]);
                allocation[i]=-1;
        }
        for(i=0;i<no_of_process;i++)
        {
                bestindex=-1;
                for(j=0;j<no_of_blocks;j++)
                {
                        if(block[j]>=process[i])
                        {
                                if(bestindex==-1)
                                        bestindex=j;
                                else if(block[bestindex]>block[j])
                                        bestindex=j;
                        }
                }
                if(bestindex!=-1)
                {
                        allocation[i]=block[bestindex];
                        block[bestindex]=block[bestindex]-process[i];
                }
        }
        printf("After allocation:\n");
        printf("Process no\tProcess size\tBlock size\n");
        for(i=0;i<no_of_process;i++)
        {
                if(allocation[i]!=-1)
                        printf("%d\t\t%d\t\t%d\n",i+1,process[i],allocation[i]);
                else
                {
                        printf("%d\t\t%d",i+1,process[i]);
                        printf("\t\tCan't be allocated\n");
                }
        }
}

