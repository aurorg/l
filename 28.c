#include<stdio.h>//头文件
int main()//主函数
{
  int max_Fun(int x,int y);//函数声明
  int a,b,max;//定义整型变量
  printf("请输入两个数：");//提示语句
  scanf("%d,%d",&a,&b);//键盘输入两个数，注意用逗号隔开
  max=max_Fun(a,b);//调用max_Fun
  printf("大的数是：%d",max);//输出结果
  return 0;//主函数返回值为0
}
int max_Fun(int x,int y)//自定义比大小函数
{
  int temp;//定义中间变量
  temp=x>y?x:y;//把大的数赋值给temp
  return temp;//把temp的结果返回到函数调用处
}
