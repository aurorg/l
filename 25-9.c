#include "stdio.h"
#include "string.h"

int main()
{
	char a[5][80],t[80];
	int i,j;
	for(i=0;i<5;i++)
	scanf("%s",a[i]);
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(strcmp(a[i],a[j])>0)
			{
				strcpy(t,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],t);
			}
		}
	}
	printf("After sorted:\n");
	for(i=0;i<5;i++)
	printf("%s\n",a[i]);
	return 0;
 }
