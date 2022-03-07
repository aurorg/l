#include<stdio.h>//头文件
int main()//主函数入口
{
  int i,j;//定义整型变量
  int array[10][10];//定义二维数组
  for(i=0;i<10;i++)//for循环
  {
    array[i][i]=1;//给二维数组的每一行的最后一个赋值为1
    array[i][0]=1;//第二维数组的每一行的开头赋值为1
  }
  
  for(i=2;i<10;i++)//外层循环限制行
  {
    for(j=1;j<=i-1;j++)//内层循环限制列
    {
      array[i][j]=array[i-1][j]+array[i-1][j-1];//给中间的数赋值
    }
  }
  
  for(i=0;i<10;i++)//外层循环限制行
  {
    for(j=0;j<=i;j++)//内层循环限制列
    {
      printf("%6d",array[i][j]);//输出二维数组，宽度为6
    }
  printf("\n");//换行
  }
  return 0;//函数返回值为0
}
