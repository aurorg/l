//do while循环
#include<stdio.h>//头文件
int main()//主函数
{
  int i=1,sum=0;//定义变量
  do{
    sum=sum+i;//和
    i=i+1; //增量
  }while(i<101); //循环条件
  printf("%d",sum);//输出结果
  return 0;//函数返回值为0
}
