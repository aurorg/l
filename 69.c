#include<stdio.h>//头文件
#include<string.h>//引入求字符串长度的库函数
int main()//主函数
{
  char str1[80],str2[80];//定义字符数组
  int i;//定义整型变量
  printf("输入要复制的字符串：");//提示语句
  scanf("%s",str2);//输入字符串
  for(i=0;i<=strlen(str2);i++)//遍历
  {
    str1[i]=str2[i];//挨个赋值
  }
  printf("复制后的字符串是:%s\n",str1);//输出复制后的
  return 0;//主函数返回值为0
}
