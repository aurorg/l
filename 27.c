#include<stdio.h>//头文件
int main()//主函数
{
  int special_Symbols();//声明自定义的special_Symbols方法
  int text();//声明自定义的text方法
  special_Symbols();//调用special_Symbols方法
  text();//调用text方法
  special_Symbols();//调用special_Symbols方法
  return 0;//函数返回值为0
}
int special_Symbols()//自定义函数，功能是输出一行*符号
{
  printf("*****************\n");
}
int text()//自定义函数，功能是输出I love you!\n
{
  printf("I love you!\n");
}
