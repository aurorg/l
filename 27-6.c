#include<stdio.h>
struct student
{
  char num[6];
  char name[10];
  int score[3];
  int sum;
};

int main()
{
  int n,i,j,max;
  scanf("%d",&n);
  struct student stu[n];
  for(i=0;i<n;i++)
  {
  	fflush(stdin);
  scanf("%s %s %d %d %d",stu[i].num,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
  stu[i].sum=stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
  }
  max=stu[0].sum;
  j=0;
  for(i=1;i<n;i++)
  if(stu[i].sum>max)
  {
  	max=stu[i].sum;
  	j=i;
   } 
  printf("%s %s %d\n",stu[j].name,stu[j].num,stu[j].sum);
  return 0;
}
