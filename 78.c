#include<stdio.h>//头文件
int main()//主函数
{
  int sum_Length(char *point);//函数声明
  int len;//定义整型变量
  char str[20];//定义字符数组
  printf("请输入要求长度的字符串：");//提示语句
  scanf("%s",str);//因为str是数组，不用加取地址符&
  len=sum_Length(str);//函数调用
  printf("字符串的长度是%d\n",len);//输出结果
  return 0;//主函数返回值为0
}
int sum_Length(char *point)//函数功能的实现
{
  int number=0;//定义整型变量
  while(*point!='\0')
  {
    number++;
    point++;
  }
  return number;//将number返回到函数调用处
}
