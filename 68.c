#include<stdio.h>//头文件
int main()//主函数
{
  int i,result;//定义整型变量
  char s1[100],s2[100];//定义字符数组
  printf("输入字符1：");//提示语句
  gets(s1); //键盘录入，空格也算
  printf("\n输入字符2：");//提示语句
  gets(s2); //键盘录入
  i=0;//赋初值
  while((s1[i]==s2[i])&&(s1[i]!='\0'))
  {
    i++; //逐个比较
  }
  if(s1[i]=='\0'&&s2[i]=='\0')
  {
    result=0;
  }
  else
  {
    result=s1[i]-s2[i]; //按照ASCII码表输出差值
  }
  printf("\n输出结果：%d\n",result);
  return 0;//主函数返回值为0
}
