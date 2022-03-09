Aurora🦋:
#include<stdio.h>//头文件
#include<math.h>//为了调用sqrt函数
#define M 1000 //宏定义
int main()
{
  int number,number_Sqrt;//定义整型变量
  printf("请输入一个小于%d的数i：",M);//提示语句
  scanf("%d",&number);//键盘输入
  if(number>M) //求平方根之前，先进行一个合法性检验
  {
    printf("输入的数据不是整数，请重新输入一个小于%d的整数i：",M);//提示语句
    scanf("%d",&number);//键盘输入
  }
  number_Sqrt=sqrt(number);//输入的数的平方根是
  printf("%d的平方根的整数部分是%d\n",number,number_Sqrt);//输出结果
  return 0;//主函数返回值为0
}

Aurora🦋:
#include<stdio.h>//头文件
int main()//主函数
{
  int temp,num1,num2,num3,num4;//定义整型变量
  printf("请输入四个数：");//提示语句
  scanf("%d %d %d %d",&num1,&num2,&num3,&num4);//注意这里键盘录入的时候也要有空格
  if(num1>num2) //读者可以考虑怎么优化，三目运算符或者冒泡排序
  {
    temp=num1;
    num1=num2;
    num2=temp;
  }
  if(num1>num3)
  {
    temp=num1;
    num1=num3;
    num3=temp;
  }
  if(num1>num4)
  {
    temp=num1;
    num1=num4;
    num4=temp;
  }
  if(num2>num3)
  {
    temp=num2;
    num2=num3;
    num3=temp;
  }
  if(num3>num4)
  {
    temp=num3;
    num3=num4;
    num4=temp;
  }
  printf("排序后的结果：\n");//提示语句
  printf("%d %d %d %d",num1,num2,num3,num4);
  return 0;//主函数返回值为0
}
