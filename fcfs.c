#include<stdio.h>
void main()
{
    int i,n,bt[10],wt[10],tat[10];
    float avwt,avtat;
    printf("Enter the Number of process\t:");
    scanf("%d",&n);
    printf("Enter the bust time\t:");
    for(i=0;i<n;i++)
    scanf("%d",&bt[i]);
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        wt[i]=wt[i-1]+bt[i-1];
    }
    printf("\nProcess \t Burst time \t Waiting time \t Trun around time\n");
    printf("----------------------------------------------------------------\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    avwt/=(float)n;
    avtat/=(float)i;
    printf("\nnAverage Waiting Time  :\t%f",avwt);
    printf("\nAverage Turnaround Time:\t%f\n ",avtat);  
}