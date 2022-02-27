#include<stdio.h>
struct student
{
  char name[10];
  float x;
  float y;
  float z;
};
int main()
{
  int n,i;
  scanf("%d",&n);
  struct student stu[n];
  float s[n];
  for(i=0;i<n;i++)
  {
  	fflush(stdin);
  scanf("%s %f %f %f",stu[i].name,&stu[i].x,&stu[i].y,&stu[i].z);
  s[i]=stu[i].x+stu[i].y-stu[i].z;
  }
  for(i=0;i<n;i++)
  printf("%s %.2f\n",stu[i].name,s[i]);
  return 0;
}
