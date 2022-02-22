#include<stdio.h>

int main()
{
  int M,N,i,j,num=0,sum=0,flag=0;
  scanf("%d %d",&M,&N);
  if(M==N)
  {
  	if(M<2) flag=0;
    else
    {
      flag=1;
      for(j=2;j<M;j++)
      {
        if(M%j==0)
        {
          flag=0;
          break;
        }
      }
    }
    if(flag==1)
    {
	   num++;
       sum+=M;
    }
  }
  else if(M!=N)
  {
    for(i=M;i<=N;i++)
    {
    if(i<2) flag=0;
    else
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
    }
    if(flag==1)
    {
       num++;
       sum+=i;
    }
    }
  }
  printf("%d %d",num,sum);
  return 0;
}
