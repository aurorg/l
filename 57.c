#include<stdio.h>//头文件
int main()//主函数
{
  int day,day_1,day_2;//定义整型变量
  day=9;//赋初值
  day_2=1;//赋初值
  while(day>0)//while循环，当day大于0时
  {
    day_1=(day_2+1)*2;//第1天的桃子数是第2天桃子数加1后的2倍
    day_2=day_1;
    day--;
  }
  printf("第一天共摘了%d个桃子\n",day_1);//输出结果
  return 0;//主函数返回值为0
}
