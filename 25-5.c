#include "stdio.h"

int main()
{
	int i,n,t,j;
	int sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	  t=1;
	  for(j=1;j<=i;j++)
		t*=j;
		sum+=t;
	}
	printf("%d",sum);
}
