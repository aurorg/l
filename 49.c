#include<stdio.h>//头文件
int main()//主函数
{
  char character_1,character_2;//定义字符
  printf("请输入两个字符；\n");//提示语句
  character_1=getchar();//键盘输入字符character_1
  character_2=getchar();//键盘输入字符character_2
  printf("用putchar语句输出结果为：");//提示语句
  putchar(character_1);//输出字符character_1
  putchar(character_2);//输出字符character_2
  printf("\n");
  printf("--------------\n");//分隔符号
  printf("用printf语句输出结果为：\n");//提示语句
  printf("%c\n",character_1);//输出字符character_1
  printf("%c\n",character_2);//输出字符character_2
  return 0;//主函数返回值为0
}
