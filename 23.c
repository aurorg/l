#include<stdio.h>//头文件
int main()//主函数
{
  int i,j,t;//定义整型变量
  int array[10];//定义数组大小
  printf("请输入十个数:");//提示语句
  for(i=0;i<10;i++)//手动往数组里输入10个数
  {
    scanf("%d,",&array[i]);//注意&符号
  }
  for(j=0;j<9;j++)//外层循环限制
  {
    for(i=0;i<9-j;i++)//内存循环
    if(array[i]>array[i+1])//如果前一个数比后一个数大
    {
      t=array[i]; //把小的数赋值给前面，大的数赋值给后面
      array[i]=array[i+1];
      array[i+1]=t;
    }
  }
  printf("按照从小到大的顺序排序:");//提示语句
  for(i=0;i<10;i++)//循环输出10个数
  {
    printf("%d ",array[i]);
  }
  printf("\n");//换行
  return 0;//函数返回值为0
}
