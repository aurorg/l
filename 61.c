#include<stdio.h>//头文件
int main()//主函数
{
  int array[3][3],sum=0;//定义二维数组和变量
  int i,j;//定义整型变量，主要用于for循环
  printf("输入数据：\n");//提示语句
  for(i=0;i<3;i++)//外层循环
  {
    for(j=0;j<3;j++)//内层循环
    {
      scanf("%3d",&array[i][j]);//键盘录入数据
    }
  }
  for(i=0;i<3;i++)//循环
  {
    sum=sum+array[i][i];//求对角线上的数之和
  }
  printf("sum=%d\n",sum);//输出结果
  return 0;//主函数返回值为0
}
