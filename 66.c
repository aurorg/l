#include<stdio.h>//头文件
int main()//主函数
{
  int j,n;//定义整型变量
  char ch[80],tran[80];//定义字符数组
  printf("输入密码：\n");//提示语句
  gets(ch);//键盘输入
  printf("\n密码是：\n%s",ch);//密码
  j=0;//赋初值
  while(ch[j]!='\0')//不是最后一个字符时
  {
    if((ch[j]>='A')&&(ch[j]<='Z'))//ASCII中A对应的值是65，a对应的值是97
    {
      tran[j]=155-ch[j];
    }
    else if((ch[j]>='a')&&(ch[j]<='z'))//小写
    {
      tran[j]=219-ch[j];
    }
    else
    {
      tran[j]=ch[j];
    }
    j++;
  }
  n=j;
  printf("\n输出原文：\n");//提示语句
  for(j=0;j<n;j++)//遍历输出
  {
    putchar(tran[j]);
  }
  printf("\n");//换行
  return 0;//函数返回值为0
}
