#include<stdio.h>//头文件
int main()//主函数
{
  char character_Big,character_Small;//定义字符变量
  printf("请输入字母：");
  scanf("%c",&character_Big);//键盘输入字符
  character_Small=(character_Big>='A'&&character_Big<='Z')?(character_Big+32):character_Big;
  printf("%c\n",character_Small);//输出
  return 0;//函数返回值为0
}
