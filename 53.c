#include<stdio.h>//头文件
int main()//主函数
{
  double sum=0,temp=1;//双精度浮点型变量
  int i;//定义整型变量
  for(i=1;i<=20;i++)//for循环
  {
    temp=temp*i;
    sum=sum+temp;
  }
  printf("结果：%22.15e\n",sum);//输出结果，注意输出的格式
  return 0;//主函数返回值为0
}
