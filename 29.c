#include<stdio.h>//头文件
int main()//主函数
{
  int age(int temp);//函数声明
  int number;//定义变量
  int people_Age;//定义变量
  printf("输入想知道的第几个孩子："); //提示语句
  scanf("%d",&number);//键盘输入想知道第几个函数
  people_Age=age(number);//调用age函数
  printf("第%d个学生的年龄是%d岁\n",number,people_Age);//输出年龄
  return 0;//主函数返回值为0
}
int age(int temp)//自定义递归函数，参数temp类型是整型
{
  int peple_Age;//定义变量
  if(temp==1)//如果temp=1
  {
    peple_Age=10;//年龄是10岁
  }
  else
  {
    peple_Age=age(temp-1)+2;//年龄等于比前一个大2岁
  }
  return peple_Age;//将年龄返回到age函数调用处
}
