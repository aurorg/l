#include "stdio.h"

int main()
{
  long n;
  float m;
  scanf("%ld",&n);  
  if(n<=1600)  m=0.0;
  else if(n<=2500)  m=0.05*(n-1600);
  else if(n<=3500)  m=0.1*(n-1600);
  else if(n<=4500)  m=0.15*(n-1600);
  else  m=0.2*(n-1600);
  printf("%.2f",m);
  return 0;
}
