#include "stdio.h"

int main()
{
	int m,n,i,j,k;
	scanf("%d %d",&m,&n);
	int a[n][n],t[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	for(j=0;j<m;j++)
	{
		for(k=0;k<n;k++)
		t[k]=a[k][n-1];

		for(i=n-2;i>=0;i--)
		{
			for(k=0;k<n;k++)
			a[k][i+1]=a[k][i];
		}
		
		for(k=0;k<n;k++)
		a[k][0]=t[k];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
 }
