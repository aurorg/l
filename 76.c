#include<stdio.h>//头文件
int main()//主函数
{
  void move(int [20],int n,int m); //函数声明
  int number[20],n,m,i;//定义整型变量和整型数组
  printf("共有多少个数：");//提示语句
  scanf("%d",&n);//键盘输入
  printf("输入这%d个数\n",n);//提示语句
  for(i=0;i<n;i++)
  {
    scanf("%d",&number[i]); //键盘录入n个数
  }
  printf("向后移动多少个数：");//提示语句
  scanf("%d",&m);//键盘输入
  move(number,n,m); //move函数调用
  for(i=0;i<n;i++)//输出结果
  {
    printf("%d ",number[i]);
  }
  printf("\n");//换行
  return 0;//主函数返回值为0
}
void move(int array[20],int n,int m)//move函数功能的实现
{
  int *p,array_end;//定义指针变量和整型数组
  array_end=*(array+n-1);
  for(p=array+n-1;p>array;p--)
  {
    *p=*(p-1);
  }
  *array=array_end;
  m--;
  if(m>0)
  {
    move(array,n,m);//递归调用，当循环次数m减至为0时，停止调用
  }
}
