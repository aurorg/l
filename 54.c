#include<stdio.h>//头文件
int main()//主函数
{
  int i,j,k,narcissistic_Number;//定义整型变量
  printf("水仙花数是：\n");//提示语句
  //小林这里要测试的100~1000之间的水仙花数
  for(narcissistic_Number=100;narcissistic_Number<1000;narcissistic_Number++)
  {
    i=narcissistic_Number/100;//百位数字
    j=narcissistic_Number/10-i*10;//十位数字
    k=narcissistic_Number%10;//各位数字
    if(narcissistic_Number==i*i*i+j*j*j+k*k*k)//符合其各位数字立方和等于该数本身
    {
      printf("%d ",narcissistic_Number);//输出这个数
    }
  }
  printf("\n");//换行
  return 0;//主函数返回值为0
}
