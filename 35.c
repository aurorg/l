#include<stdio.h>//头文件
int main()//主函数
{
  char *p="I love C program language";//定义指针变量且赋值
  p=p+7;//指针变量p指向字符串的第8位
  printf("%s",p);//输出
  return 0;//主函数返回值为0
}
