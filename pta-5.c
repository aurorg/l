#include<stdio.h>
int main()
{
  char character1,character2,character3,character4;//定义字符变量
  character1='L';//初始化变量，将字符L赋值给character1
  character2='o';//初始化变量，将字符o赋值给character2
  character3='v';//初始化变量，将字符v赋值给character3
  character4='e';//初始化变量，将字符e赋值给character3
  putchar(character1);//输出字符L
  putchar(character2);//输出字符o
  putchar(character3);//输出字符v
  putchar(character4);//输出字符e
  putchar('\n');//换行
  return 0;//函数返回值为0
}
