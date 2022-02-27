#include<stdio.h>

struct frt
{
  char name[10];
  long date;
  char phone[17];
};

int main()
{
  int n,i,j;
  scanf("%d",&n);
  struct frt fri[n],t;
  for(i=0;i<n;i++)
  {
  	fflush(stdin);
  scanf("%s %ld %s",fri[i].name,&fri[i].date,fri[i].phone);
  }
  
  for(i=0;i<n-1;i++)
  {
  	for(j=i+1;j<n;j++)
  	{
  		if(fri[i].date>fri[j].date)
  		{
  			t=fri[i];
  			fri[i]=fri[j];
  			fri[j]=t;
		  }
	  }
  }
for(i=0;i<n;i++) 
{
printf("%s %ld %s\n",fri[i].name,fri[i].date,fri[i].phone);
}
  
  return 0;
}
