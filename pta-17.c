#include<stdio.h>//头文件
#include<math.h>//为了引入sqrt求平方根函数
int main()//主函数
{
  int number,i;//定义变量
  for(number=100;number<201;number++)//这个for循环主要是限制100-200之间
  {
    for(i=2;i<=sqrt(number);i++)
    {
      if(number%i==0)//如果余数为0
      break;//跳出当前循环
    }
      if(number%i!=0)//如果求余不等于0，则为素数
    printf("%d\n",number);//输出素数
   }
   return 0;//函数返回值为0
}
