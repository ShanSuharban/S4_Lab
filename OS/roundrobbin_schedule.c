#include<stdio.h>
int main()
{
	int bt[10],at[10],n,slice,count=0,i,j,k,temp,t,rt[10],ct[10],wt[10],tat[10];
	int now[10],b=0;
	int totwt=0,totta=0;
	float awt,ata;
	printf("*****Round Robin Scheduling*****\n");
	printf("Enter the number of process:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the details for process%d\n",i);
		printf("Enter the arrival time:");
		scanf("%d",&at[i]);
		printf("Enter the burst time:");
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	printf("\nEnter the time_quantum:");
	scanf("%d",&slice);
	printf("Before scheduling:");
	printf("\nPname\tarrivaltime\tbursttime");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t%d\t\t%d",i,at[i],bt[i]);
	}
	t=at[0];
	for(i=1;i<n;i++)
	{
		if(t>at[i])
		{
			t=at[i];
		}
	}
	for(i=0;i<n;)
		{
			for(j=0;j<n;j++)
			{
				if(at[j]==t)
				{
					now[b]=j;
					b++;
				}
			}
			if(b==0)
			{
				t++;
			}
			else if(b==1)
			{
				t++;
				count++;
				rt[now[0]]--;
				if(rt[now[0]]==0)
				{
					b--;
					ct[now[0]]=t;
					i++;
					count=0;
				}
			
			if(count==slice)
			{
				count=0;
			}
		}
			else
			{
				t++;
				count++;
				rt[now[0]]--;
				if(rt[now[0]]==0)
				{
					ct[now[0]]=t;
					i++;
					count=0;
					for(k=0;k<b-1;k++)
					{
						now[k]=now[k+1];
					}
					b--;
				}
				if(count==slice)
				{
					temp=now[0];
					for(k=0;k<b-1;k++)
					{
						now[k]=now[k+1];
					}
					now[b-1]=temp;
					count=0;
				}
			}
		}
		
		printf("\n\nAfter scheduling:");
		printf("\nPname\tarrival time\tburst time\tcompletion time\twaiting time\tTattime");
		for(i=0;i<n;i++)
		{
			tat[i]=ct[i]-at[i];
			wt[i]=tat[i]-bt[i];
			totwt+=wt[i];
			totta+=tat[i];
			printf("\nP%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d",i,at[i],bt[i],ct[i],wt[i],tat[i]);
		}
		awt=(float)totwt/n;
		ata=(float)totta/n;
		printf("\nAverage waiting time:%f",awt);
		printf("\nAverage turnaround time:%f",ata);
		return 0;
}
