#include<stdio.h>
int main()
{
    int n,i,bt[10],pri[10],wt[10],tat[10],p[10],j,temp,pos;
    float avwt,avtat;
    printf("Enter the number of process\t:");
    scanf("%d",&n);
    printf("Enter %d Burst time\t:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    printf("Enter the priority\t:");
    for(i=0;i<n;i++)
        scanf("%d",&pri[i]);
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pri[pos]>pri[j])
                pos=j;
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;

        temp=pri[i];
        pri[i]=pri[pos];
        pri[pos]=temp;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        wt[i]=wt[i-1]+bt[i-1];
    }
    printf("\nPriority\tProcess\tBurst Time\tWaiting Time\tTurn around Time\n");
    for(i=0;i<n;i++)
    {  
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("    %d   \t%d  \t     %d    \t      %d    \t    %d\n",pri[i],p[i],bt[i],wt[i],tat[i]);
    }
    avwt/=(float)n;
    avtat/=(float)n;
    printf("\nnAverage Waiting Time  :\t%f",avwt);
    printf("\nAverage Turnaround Time:\t%f\n ",avtat);  
    return 0;
}