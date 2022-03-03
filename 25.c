#include<stdio.h>//头文件
int main()//主函数
{
  int i,j;//定义整型变量
  int row,column,max;//定义行号、列号、最大值变量
  int array[3][4]={{1,2,3,4},{90,8,7,6},{-10,10,-5,2}};//定义二维数组且赋值
  for(i=0;i<3;i++)//外层循环限制行，3行
  {
    for(j=0;j<4;j++)//外层循环限制列，4列
    {
      printf("%3d ",array[i][j]);//输出数组，宽度为3 
    }
    printf("\n");//换行
  }
  printf("------------------\n");//分割开
  max=array[0][0];//先把数组的第一个数赋值给max
  for(i=0;i<3;i++)//外层循环限制行，3行
  {
    for(j=0;j<4;j++)//外层循环限制列，4列
    if(array[i][j]>max)//将数组中的每个数与第一个进行比较
    {
      max=array[i][j];//把大的赋值给max
      row=i;//把大的数的行号赋值给row
      column=j;//把大的数的列号赋值给column
    }
  }
  printf("max=%d\n",max);//输出最大的数
  printf("行号是：%d\n",row+1);//行号
  printf("列号是：%d\n",column+1);//列号
  return 0;//函数返回值为0
}
