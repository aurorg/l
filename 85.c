#include<stdio.h>//头文件
int main()//主函数
{
  int a,number,count=1;//定义整型变量
  long int sum=0,temp=0;//定义长整型变量
  printf("请输入a 和 number：");//提示语句
  scanf("%d %d",&a,&number);//键盘输入
  printf("a=%d,number=%d\n",a,number);
  while(count<=number)//循环条件
  {
    temp=temp+a;
    sum=sum+temp;
    a=a*10;
    ++count;
  }
  printf("a+aa+...=%ld\n",sum);//输出结果
  return 0;//主函数返回值为0
}
