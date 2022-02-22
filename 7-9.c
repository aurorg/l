#include <stdio.h>
#include <math.h>

int main()
{
  int n,i,j,k,mod,x,y,sum;
  scanf("%d",&n);
  for(i=pow(10,n-1);i<pow(10,n)-1;i++)
  {
    sum=0;
    x=i;
    for(j=1;j<=n;j++)
    {
    y=x%10;
    mod=1;
    for(k=1;k<=n;k++) mod*=y;
    sum+=mod;
    if(sum>i) break;
    x=x/10;
	}
	if(sum==i)
    printf("%d\n",i);
  }
  return 0;
}
