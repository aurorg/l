#include<stdio.h>//头文件
int main()//主函数
{
  int i,n,m; //定义整型变量
  int odd_Number=0,even_Number=0; //同上且赋初值
  printf("请输入要判断几个数：");
  scanf("%d",&n);//输入整数的个数
  printf("输入这几个数：");
  for(i=0;i<n;i++) //循环
  {
    scanf("%d",&m);
    if(m%2!=0) //判断条件
    {
      odd_Number++;//奇数
    }
    else
    {
      even_Number++;//偶数
    }
  }
  printf("奇数：%d个\n偶数：%d个：\n",odd_Number,even_Number);
  return 0;//函数返回值为0
}
