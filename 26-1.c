#include "stdio.h"

int main()
{
	int i,j,n,x;
	scanf("%d",&n);
	int a[n+1];
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&x);
	if(n<=0)
	{
		a[0]=x;
	}
	else
	{
		for(j=n-1;x<a[j]&&j>=0;j--)
		a[j+1]=a[j];
		a[++j]=x;
	}
	for(i=0;i<n+1;i++)
	printf("%d ",a[i]);
	return 0;
}
