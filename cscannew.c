#include <stdio.h> 
#include <stdlib.h> 
int main()
{
 int RQ[100], i, j, n, totalheadmoment=0, initial, size, move;
 printf("Enter the no of requests:");
 scanf("%d",&n);
 printf("Enter the request sequence:");
 for(i=0;i<n;i++)
 {scanf("%d",&RQ[i]);}
 printf("Enter the initial head position:");
 scanf("%d",&initial);
 printf("Enter the total disk size:");
 scanf("%d",&size);
 printf("Enter the head movement direction(0/1):");
 scanf("%d",&move);
 
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  { 
   if(RQ[j]>RQ[j+1])
   {
    int temp;
    temp = RQ[j];
    RQ[j]=RQ[j+1];
    RQ[j+1]= temp;
   }
  }
 }
 
  int index;
  for(i=0;i<n;i++)
  {
   if(initial<RQ[i])
   { index = i;
     break;
    }
   }
   
  if(move==1)
  {
   for(i=index;i<n;i++)
   {
    totalheadmoment+=abs(RQ[i]-initial);
    initial=RQ[i];
   }
   totalheadmoment+=abs(size-RQ[i-1]-1);
   totalheadmoment+=abs(size-1-0);
    initial=0;
    for(i=0;i<index;i++)
    {
    totalheadmoment+=abs(RQ[i]-initial);
    initial=RQ[i];
    }
    }
    else
    {
     for(i=index-1;i>=0;i--)
   {
    totalheadmoment+=abs(RQ[i]-initial);
    initial=RQ[i];
   }
   totalheadmoment+=abs(RQ[i+1]-0);
   totalheadmoment+=abs(size-1-0);
    initial=size-1;
    for(i=size-1;i>=index;i--)
    {
    totalheadmoment+=abs(RQ[i]-initial);
    initial=RQ[i];
    }
    }
 printf("The total head movement : %d",totalheadmoment);
 return(0);
}
