#include<stdio.h>//头文件
int main()//主函数
{
  register int i;//定义寄存器变量
  int temp=0;//定义整型变量
  for(i=0;i<=100;i++)//求和
  {
    temp=temp+i;
  }
  printf("和是：%d\n",temp);//输出结果
  return 0;//主函数返回值为0
}
