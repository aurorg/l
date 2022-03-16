#include<stdio.h>//头文件
int main()//主函数
{
  int sum_day(int month,int day);//函数声明
  int leap(int year);//函数声明
  int year,month,day,days;//定义整型变量
  printf("输入日期：") ;
  scanf("%d %d %d",&year,&month,&day);
  printf("%d-%d-%d",year,month,day);
  days=sum_day(month,day); //调用函数sum_day
  if(leap(year)&&month>=3) //调用函数leap
  {
    days=days+1;
  }
  printf("是这一年的第%d天\n",days);
  return 0;//主函数返回值为0
}
int sum_day(int month,int day)//自定义函数
{
  int day_tab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//定义整型数组
  int i;//定义整型变量
  for(i=1;i<month;i++)//for循环
  {
    day+=day_tab[i]; //加所在月之前的天数
  }
  return day;//将day返回到函数调用处
}
int leap(int year)//判断是否为闰年
{
  int leap;//定义整型变量
  leap=(year%4==0&&year%100!=0||year%400==0);//赋初值
  return leap;//将leap返回到函数调用处
}
