#include<stdio.h>//头文件
int main()//主函数
{
  int factorial(int number);//自定义阶乘函数声明
  int number,temp;//定义变量
  printf("输入要求阶乘的数：");//提示语句
  scanf("%d",&number);//键盘输入相求的数
  temp=factorial(number);//调用阶乘函数
  printf("%d!=%d",number,temp) ;//输出结果
  return 0;//主函数返回值为0
}
int factorial(int number)//自定义阶乘函数
{
  int temp;//定义整型变量
  if(number<0)//如果这个数小于0
  {
    printf("错误数据请，输入大于0的数！");//不符合条件，无法求
  }
  else if(number==0||number==1)//0或者1本身的阶乘是1
  {
    temp=1;
  }
  else
  {
    temp=factorial(number-1)*number;//否则求这个数与前一个数相乘的结果
  }
  return temp;//将temp返回到函数调用处
}
