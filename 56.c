#include<stdio.h>//头文件
int main()//主函数
{
  int i;//定义整型变量，用于for循环
  double a=2,b=1,sum=0,temp;//定义双精度浮点型变量
  for(i=1;i<=20;i++)//for循环
  {
    sum=sum+a/b;//分母为前面的分子和分母之和
    temp=a;
    a=a+b;
    b=temp;//分子为前面的分母
  }
  printf("sum=%7.7f\n",sum);//输出和
  return 0;//主函数返回值为0
}
