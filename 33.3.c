#include<stdio.h>//头文件
int main()//主函数
{
  int array[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};//定义二维数组，且赋初值
  int *p,m;//定义指针变量和普通变量
  for(m=0,p=array[0];p<array[0]+12;p++,m++)//for循环
  {
    if(m%4==0)//如果m%4的余数为0
    {
      printf("\n");//换行
    }
  printf("%4d",*p);//输出元素值，宽度为4
    }
    printf("\n");//换行
    return 0;//主函数返回值为0
} 
