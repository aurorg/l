#include<stdio.h>//头文件
int main()//主函数
{
  char input_Character;//定义字符变量
  int letters=0,space=0,digit=0,other=0;//定义整型变量且赋初值
  printf("请输入一行字符：");//提示语句
  while((input_Character=getchar())!='\n') //getchar函数录入，可以把空格也算做字符
  {
    if(input_Character>'a'&&input_Character<'z'||input_Character>'A'&&input_Character<'Z')//如果是字母
    {
      letters++;//letters加1
    }
    else if(input_Character==' ')//如果是空格
    {
      space++;//sapce加1
    }
    else if(input_Character>='0'&&input_Character<='9')//如果是数字
    {
      digit++;//digit加1
    }
    else
    {
      other++;//other加1
    }
  }
  printf("字母：%d个\n",letters);//输出字母个数
  printf("空格：%d个\n",space);//输出空格个数
  printf("数字：%d个\n",digit);//输出数字个数
  printf("其他字符：%d个\n",other);//输出其他字符个数
  return 0;//主函数返回
}
