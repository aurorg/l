#include<stdio.h>//头文件
int main()//主函数
{
  int year;//定义整型变量
  printf("随意输入一年：");//提示语句
  scanf("%d",&year);//键盘输入年份
  if((year%4==0 && year%100!=0)||year%400==0)//判断闰年的条件
  {
    printf("%d是闰年\n",year);
  }
  else
  {
    printf("%d不是闰年\n",year);
  }
  return 0; //函数返回值为0
}
