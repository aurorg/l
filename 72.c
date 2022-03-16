#include<stdio.h>//头文件
int main()//主函数
{
  int temp,num;//定义整型变量
  float num_Polynomial;//定义浮点型变量
  float polynomial(int,int);//函数声明
  printf("输入num & temp:");//提示语句
  scanf("%d,%d",&num,&temp);//键盘输入
  num_Polynomial=polynomial(num,temp); //求值
  printf("Polynomial=%6.2f\n",num_Polynomial);//输出结果
  return 0;//主函数返回值为0
}
float polynomial(int number,int x)//自定义函数
{
  if(number==0)//if语句判断number符合哪一个条件
  {
    return(1);
  }
  else if(number==1)
  {
    return(x);
  }
  else
  {
    return(2*number-1)*x*polynomial((number-1),x)-(number-1)*polynomial((number-2),x)/number;
  }
}
