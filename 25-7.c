#include "stdio.h"

int main()
{
	char s[80];
	int i=0,j;
	while((s[i]=getchar())!='\n')
	{
		if(s[i]>='A' && s[i]<='Z')
		s[i]=90-s[i]+65;
		i++;
	}
  for(j=0;j<i;j++)
	{
	  printf("%c",s[j]);
	}
	return 0;
 }
