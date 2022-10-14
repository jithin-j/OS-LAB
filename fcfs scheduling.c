#include<stdio.h>

struct fcfs{
int pid;
int at;
int bt;
int wt;
int tt;
int ct;

}p[10],temp;

void main()
{ int np,i,j,tottt=0,totwt=0,n;
  printf("fcfs scheduling");
 printf("\nenter number of processes ");
 scanf("%d",&n);
 printf("\nenter arrival time and burst time ");

 for(i=0;i<n;i++)
 { printf("\nprocess%d: ",i+1);
     scanf("%d%d",&p[i].at,&p[i].bt);
   p[i].pid=i+1;
   }
 
 

for(i=0;i<n;i++)
{for(j=i+1;j<n;j++)
{ if(p[i].at > p[j].at)
   { temp=p[j];
	p[j]=p[i];
	p[i]=temp;
    }
}}


p[0].wt=0;
p[0].tt=p[0].bt;
p[0].ct=p[0].at+p[0].bt;
tottt=tottt+p[0].tt;


for(i=1;i<n;i++)
{ p[i].wt=(p[i].at-p[i-1].ct>=0)?0:p[i-1].ct-p[i].at;
  p[i].tt=p[i].wt+p[i].bt;
  p[i].ct=p[i].at+p[i].bt+p[i].wt;
  tottt=tottt+p[i].tt;
  totwt=totwt+p[i].wt;
}


printf("\nprocess\tAT\tBT\tCT\tTT\tWT\n");

for(i=0;i<n;i++)
{
  printf("%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);

}

printf("\ntotal turnaroundtime is %d",tottt);
printf("\navg turnaround time is %f",(float)tottt/n);
printf("\ntotal waiting time is %d",totwt);
printf("\navg waiting time is %f",(float)totwt/n);
}









