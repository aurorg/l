#include"stdio.h"
int main()
{
  int n,i;
  float b,c=0,sum=0;
  scanf("%d",&n);
  int a[n];
  if(n<1)
  {
  	b=0;
  	c=0;
  	printf("average = %.1f\ncount = %.0f",b,c);
  }
  else
  {
  for(i=0;i<n;i++)
  {
  scanf("%d",&a[i]);
  sum+=a[i];
  if(a[i]>=60)
  c+=1;
  }
  b=sum/n;
  printf("average = %.1f\ncount = %.0f",b,c);
  } 
  return 0;
}
