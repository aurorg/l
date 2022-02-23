#include "stdio.h"

int main()
{
	int s,c;
	scanf("%d",&s);
	c=s/10;
	switch(c)
	{
	case 10:;
	case 9:printf("A");break;
	case 8:printf("B");break;
	case 7:printf("C");break;
	case 6:printf("D");break;
	default:printf("E");
	}
	return 0;
}
 
