#include<stdio.h> //头文件
int main() //主函数
{
  char character_Small,character_Big;//定义字符变量
  character_Big='A'; //字符变量初始化，即把赋值字母A赋值给character_Big
  character_Small=character_Big+32;//ASCII码表值+32
  printf("大写字母%c",character_Big);//输出大写字母A
  printf("的小写字母是：%c\n",character_Small);//输出小写字母a
  return 0;//函数返回值为空
}
