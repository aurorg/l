#include "stdio.h"

int main()
{
  int i;
  char c;
  float f;
  double d;
  scanf("%f %d %c %lf",&f,&i,&c,&d);
  printf("%c %d %.2f %.2lf",c,i,f,d);
  return 0;
}
