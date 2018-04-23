#include<stdio.h>
int main()
{
  int t,a[10],b[10],sum=0,small,n,i;
  int v=0,v1=0;
  printf("Enter number of Processes : ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Arrival time for process P%d : ",i+1);
    scanf("%d",&a[i]);
    printf("Burst time for process P%d : ",i+1);
    scanf("%d",&b[i]);
    sum+=b[i];
  }
  b[9]=9999;
  for(t=0;t<sum;)
  {
    small=9;
    for(i=0;i<n;i++)
    {
      if(a[i]<=t && b[i]>0 && b[i]<b[small])
        small=i;
    }
    printf("P[%d]\t|\t%d\t|\t%d\n",small+1,t+b[small]-a[small],t-a[small]);
    v1+=t+b[small]-a[small];
    v+=t-a[small];
    t+=b[small];
    b[small]=0;
  }
  printf("\n\n Average waiting time = %f",v*1.0/n);
  printf("\n\n Average turnaround time = %f",v1*1.0/n);
  return 0;
}
