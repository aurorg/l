#include<stdio.h>//头文件
int main()//主函数
{
  char grade; //定义成绩级别字符变量
  printf("输入成绩级别：");//提示语句
  scanf("%c",&grade); //键盘输入
  printf("成绩段：");//提示语句
  switch(grade) //switch多分支
  {
    case'A':printf("85-100\n");break;//输出A的成绩分布
    case'B':printf("70-84\n");break;//输出B的成绩分布
    case'C':printf("60-69\n");break;//输出C的成绩分布
    case'D':printf("不及格小于60\n");break;//输出D的成绩分布
    default:printf("输入成绩等级有误\n");//输出成绩级别有误
  }
  return 0;//函数返回值为0
}
