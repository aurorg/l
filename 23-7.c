#include "stdio.h"

int main()
{
	int i,j,n;
	double s,sum;
	scanf("%d",&n);
	sum=0.0;
	for(i=1;i<=n;i++)
	{
		s=1;
		for(j=1;j<=i;j++)
		{
			s*=j;
		}
		sum+=s;
	}
	printf("%.0lf",sum);
	return 0;
}
