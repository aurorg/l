#include<stdio.h>//头文件
int main()//主函数
{
  long int gain;//定义长整型变量
  int prize1,prize2,prize4,prize6,prize10,prize = 0;//定义整型变量
  printf("请输入利润：");//提示语句
  scanf("%ld",&gain);//键盘输入
  prize1=100000*0.1;
  prize2=prize1+100000*0.075;
  prize4=prize2+200000*0.05;
  prize6=prize4+200000*0.03;
  prize10=prize6+400000*0.015;
  if(gain<=100000)
    prize=gain*0.1;
  else if(gain<=200000)
    prize=prize1+(gain-100000)*0.075;
  else if(gain<=400000)
    prize=prize2+(gain-200000)*0.05;
  else if(gain<=600000)
    prize=prize4+(gain-400000)*0.03;
  else if(gain<=1000000)
    prize=prize6+(gain-600000)*0.015;
  else
    prize=prize10+(gain-1000000)*0.01;
  printf("奖金是：%d\n",prize);
  return 0;//函数返回值为0
}
