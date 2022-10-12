#include<stdio.h>
#include<stdlib.h>


struct sjf
{ int pid;
  int at;
  int bt; 
  int wt;
  int ct;
  int tt;
  
}p[100],temp;

void main()
{ int n,i,j,min=1000,pos,totwt=0,tottt=0;
  printf("\nenter number of process ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {  p[i].pid=i+1;
     printf("\nenter arrival time of process%d:",i+1);
     scanf("%d",&p[i].at);
    printf("\nenter burst time of process%d:",i+1);
     scanf("%d",&p[i].bt);
  }


  for(i=0;i<n;i++)
  {  for(j=i+1;j<n;j++)
     {  if(p[i].at>p[j].at)
         {  temp=p[i];
		 p[i]=p[j];
		 p[j]=temp;
  }}}

 p[0].wt=0;
 p[0].ct=p[0].at+p[0].bt;
 p[0].tt=p[0].bt;

  for(i=1;i<n;i++)
  { 
    for(j=i;j<n;j++)
    { 
      if(p[j].at<=p[i-1].ct)
      { 
        if(p[j].bt<min)
        { 
          min=p[j].bt;
          pos=j;
        }
      }
    }  
    temp=p[i];
    p[i]=p[pos];
    p[pos]=temp;

    p[i].ct=p[i-1].ct+p[i].bt;
    min=1000;
  }

for(i=0;i<n;i++)
{ p[i].tt=p[i].ct-p[i].at;
  p[i].wt=p[i].tt-p[i].bt;
  tottt+=p[i].tt;
  totwt+=p[i].wt;

}

 printf("\np\tat\tbt\tct\ttot\twt\n");
 for(i=0;i<n;i++)
{ printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
 }
 printf("\ntotal waiting time is %d",totwt);
 printf("\navg waiting time is %f",(float)totwt);
printf("\ntotal turnaround time is %d",tottt);  
printf("\navg turnaround time is %f",(float)totwt);
}














