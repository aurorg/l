#include<stdio.h>//头文件
int main()//主函数
{
  float amount,aver,total;//定义浮点型变量
  float sum=100000; //定义浮点型变量且赋初值
  int i;//定义整型变量
  for(i=1,total=0;i<1001;i++)//循环条件
  {
    printf("请依次输入捐款钱数：");//提示语句
    scanf("%f",&amount); //键盘输入
    total=total+amount;
    if(total>sum)
    break;//跳出循环
  }
  aver=total/i;
  printf("第%d个人捐款之后达到10万+\n平均每人捐款：%5.2f\n",i,aver);
  return 0;//函数返回值为0
}
