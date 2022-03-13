#include<stdio.h>//头文件
#define N 3 //宏定义
#define M 4 //宏定义
int main()//主函数
{
  int i,j,k,a[N][M],max,maxj,flag;//定义整型变量和二维数组
  printf("请输入数组：\n");//提示语句
  for(i=0;i<N;i++)
  {
    for(j=0;j<M;j++)
    {
      scanf("%d",&a[i][j]);//往数组里存数
    }
  }
  for(i=0;i<N;i++)
  {
    max=a[i][0]; //开始时假设a[i][0]最大
    maxj=0; //将列号0赋给maxj保存
    for(j=0;j<M;j++) //找出第i行中的最大数
    {
      if(a[i][j]>max)
      {
        max=a[i][j]; //将本行最大的数放在max中
        maxj=j; //将最大数所在的列号存放在maxj中
      }
    }
    flag=1; //先假设是鞍点，以flag为1代表
    for(k=0;k<N;k++)
    {
      if(max>a[k][maxj])
      { //将最大的数和其同列元素相比
        flag=0; //如果max不是同列最小，表示不是鞍点
        continue;
      }
    }
    if(flag)
    {
      printf("a[%d][%d]=%d\n",i,maxj,max); //输出鞍点的值和所在行列号
      break;
    }
  }
  if(!flag)
  {
    printf("鞍点不存在!\n");//提示语句
  }
  return 0;//主函数返回值为0
}
