#include<stdio.h>//头文件
int main()//主函数
{
  void varfunc(); //函数声明
  int i;//定义整型变量
  for(i=0;i<3;i++)//3次循环
  {
    varfunc();//调用varfunc函数
  }
  return 0;//主函数返回值为0
}

void varfunc() 
{
  int var=0;//定义整型变量
  static int static_var=0; //定义静态变量
  printf("变量var值是：%d\n",var);
  printf("静态变量static_var值是：%d\n",static_var);
  printf("\n");//换行
  var++;
  static_var++;
}
