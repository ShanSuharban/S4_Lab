#include<stdio.h>
int main()
{
        int pn[10],bt[10],at[10],p[10],n,i,j,k,l,temp,t,rt[10],ct[10],wt[10],ta[10];
        int now[10],b=0;
        int totwt=0,totta=0;
        float awt,ata;
        printf("*****priority scheduling*****\n");
        printf("Enter the number of processes:");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("Enter details for process %d\n",i);
                pn[i]=i;
                printf("Enter arrival time:");
                scanf("%d",&at[i]);
                printf("Enter burst time");
                scanf("%d",&bt[i]);
                rt[i]=bt[i];
                printf("Enter priority");
                scanf("%d",&p[i]);
        }
        printf("Before scheduling:");
        printf("\npname\tarrivaltime\tbursttime\tpriority");
        for(i=0;i<n;i++)
        {
                printf("\n%d\t%d\t\t%d\t\t%d",pn[i],at[i],bt[i],p[i]);
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
                        if((at[j]==t))
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
                        temp=now[0];
                        rt[temp]--;
                        if(rt[temp]==0)
                        {
                                b--;
                                ct[temp]=t;
                                i++;
                        }
                }
                else
                {
                for(k=0;k<b-1;k++)
                {
                        for(l=k+1;l<b;l++)
                        {
                                if(p[now[k]]<p[now[l]])
                                {
                                        temp=now[k];
                                        now[k]=now[l];
                                        now[l]=temp;
                                }
                                if(p[now[k]]==p[now[l]])
                                {
                                if(p[now[k]]<pn[now[l]])
                                {
                                        temp=now[k];
                                        now[k]=now[l];
                                        now[l]=temp;
                                }
                        }
                }
        }
        t++;
        rt[now[b-1]]--;
        if(rt[now[b-1]]==0)
        {
                ct[now[b-1]]=t;
                b--;
                i++;
        }

   }
}
printf("\n\nAfter Scheduling:");
printf("\npname\tarrivaltime\tbursttime\tpriority\tcompletion\twaitingtime\tTAtime");
for(i=0;i<n;i++)
{
        ta[i]=ct[i]-at[i];
        wt[i]=ta[i]-bt[i];
        totwt+=wt[i];
        totta+=ta[i];
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",pn[i],at[i],bt[i],p[i],ct[i],wt[i],ta[i]);
}
awt=(float)totwt/n;
ata=(float)totta/n;
printf("\nAverage waiting time is:%f",awt);
printf("\nAverage turnaroundtime is %f",ata);
return 0;
}
