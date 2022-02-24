#include "stdio.h"

int main()
{
	int i,j,sum=0,flag;
	for(i=101;i<200;i++)
	{
		flag=1;
		for(j=2;j<i;j++)
		{
			if(i%j==0) 
			{
				flag=0;
				break;
			}
		}

		if(flag==1)
		{
			sum+=i;
		}
	}
	printf("%d",sum);
	return 0;
}
