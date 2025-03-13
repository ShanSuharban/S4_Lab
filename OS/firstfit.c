#include<stdio.h>
int main()
{
        int no_of_process,no_of_blocks,block[10],process[10],allocation[10],i,j;
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
                for(j=0;j<no_of_blocks;j++)
                {
                        if(block[j]>=process[i])
                        {
                                allocation[i]=block[j];
                                block[j]=block[j]-process[i];
                                break;
                        }
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
