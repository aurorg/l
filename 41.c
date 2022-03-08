#include<stdio.h>//头文件
#define N 3//宏定义
struct student //学生类结构体
{
  int num; //学号
  char name[20];//姓名
  float score[3];//成绩
  float aver;//平均分
} ;
int main() //主函数
{
  void input(struct student s[]);//函数声明
  struct student max(struct student s[]);//函数声明
  void print(struct student s);//函数声明
  struct student s[N],*p=s;//定义结构体变量
  input (p);//调用函数
  print(max(p));//打印调用max函数结果
  return 0;//主函数返回值为0
}
 void input(struct student s[])//自定义输入函数
 {
   int i;//定义整型变量
   printf("请输入各学生的信息：学号、姓名、三门课成绩:\n");//提示语句
   for(i=0;i<N;i++)//循环N次
   {
     scanf("%d %s %f %f %f",&s[i].num,&s[i].name,&s[i].score[0],&s[i].score[1],&s[i].score[2]);//输入信息
     s[i].aver=(s[i].score[0]+s[i].score[1]+s[i].score[2])/3;//求平均值
   }
 }
 struct student max(struct student s[])//自定义求最大值
 {
   int i,m=0;//定义整型变量
   for(i=0;i<N;i++)//循环N次
  {
    if(s[i].aver>s[m].aver)//把平均分大的i赋值给m
    {
      m=i;
    }
  }
    return s[m];//将s[m]结果返回到函数调用处
 }
 void print (struct student stud)//自定义打印函数
 {
   printf("\n成绩最高的学生是：\n");//提示语句
   printf("学号；%d\n姓名；%s\n三门课成绩：%5.1f,%5.1f,%5.1f\n平均成绩：%6.2f\n",
   stud.num,stud.name,stud.score[0],stud.score[1],stud.score[2],stud.aver);//输出结果
 }
