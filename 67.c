#include<stdio.h>//头文件
int main()//主函数
{
  char str1[80],str2[40];//定义字符数组
  int i=0,j=0;//定义整型变量且赋初值
  printf("输入字符串1：");//提示语句
  scanf("%s",str1); //录入字符串1
  printf("输入字符串2：");//提示语句
  scanf("%s",str2); //录入字符串2
  while(str1[i]!='\0')//判断str1是不是最后一个字符
  {
    i++;
  }
  while(str2[j]!='\0')//判断str2是不是最后一个字符
  {
    str1[i++]=str2[j++];//逐个拼接
  }
  str1[i]='\0';
  printf("\n新的字符串是：%s\n",str1);//输出拼接后的字符串
  return 0;//主函数返回值为0
}
