#include<stdio.h>//头文件
struct student //学生结构体
{
  int num; //学号
  char name[20]; //姓名
  float score; //成绩
} ;
int main()//主函数
{
  //定义结构体变量且赋值
  struct student stu[5]={{10010,"Tom",78},{10011,"Jon",98.5},{10012,"Lisi",100},{10013,"zhangsan",99},{10014,"wangwu",10}};
  struct student t;
  int i,j,k;//定义整型变量
  printf("成绩由大到小排序：\n");//提示语句
  for(i=0;i<4;i++)//外层for循环
  {
    k=i;//把i的值赋给k
    for(j=i+1;j<5;j++)//内层for循环
    {
      if(stu[j].score>stu[k].score)//挑出分数高的
      {
        k=j;//把相应的j赋值给k
      }
    }
    t=stu[k]; //把成绩高的放到前面
    stu[k]=stu[i];
    stu[i]=t;
  }
  for(i=0;i<5;i++)//循环输出5个人的成绩
  {
    printf("%d,%10s,%6.2f分\n",stu[i].num,stu[i].name,stu[i].score);//输出结果
  }
  return 0;//主函数返回值为0
}
