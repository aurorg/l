#include<stdio.h>//头文件
int main()//主函数
{
  int num,result; //定义整型变量
  printf("请输入num:");//提示语句
  scanf("%d",&num);//键盘输入
  if(num<0) //判断条件小于0时
  {
    result=-1;
  }
  else if(num==0)//判断条件等于0时
  {
    result=0;
  }
  else //判断条件大于0时
  {
    result=1;
  }
  printf("%d\n",result);//输出结果
  return 0;//函数返回值为0
}
