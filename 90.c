#include<stdio.h>//头文件
#define TRUE 1//宏变量
#define SQUARE(x) (x)*(x)//宏定义求平方函数
int main()//主函数
{
  int num,num_Square;//定义整型变量
  printf("请输入要求平方的数：");//提示语句
  scanf("%d",&num);//键盘输入
  num_Square=SQUARE(num);//求平方
  printf("%d的平方是：%d\n",num,num_Square);//输出结果
  if(num_Square>50)
  {
    printf("%d\n",TRUE);
  }
  return 0;//函数返回值为0
}
