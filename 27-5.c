#include<stdio.h>
struct student
{
  char num[6];
  char name[10];
  int score;
};

int main()
{
  int n,i;
  float aver,sum=0;
  scanf("%d",&n);
  struct student stu[n];
  for(i=0;i<n;i++)
  {
  	fflush(stdin);
  scanf("%s %s %d",stu[i].num,stu[i].name,&stu[i].score);
  sum+=stu[i].score;
  }
  aver=sum/n;
  printf("%.2f\n",aver);
  for(i=0;i<n;i++)
  if(stu[i].score<aver) printf("%s %s\n",stu[i].name,stu[i].num);
  return 0;
}
