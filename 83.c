#include<stdio.h>//头文件
int main()//主函数
{
  int i,j,temp,array[11];//定义变量
  printf("请输入10个数：\n");//提示语句
  for(i=1;i<=10;i++)
  {
    scanf("%d",&array[i]);
  }
  for(i=1;i<=9;i++)//外层循环
  {
    for(j=i+1;j<=10;j++)//内层循环
    {
      if(array[i]>array[j]) //如果前一个数比后一个数大，则利用中间变量t实现两值互换
      {
        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
      }
    }
  }
  printf("\n排序后顺序：\n");//提示语句
  for(i=1;i<=10;i++)//输出排序后的数
  {
    printf("%5d",array[i]);
  }
  printf("\n");//换行
  return 0;//函数返回值为0
}
