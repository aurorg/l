#include <stdio.h>//头文件
#include <math.h>//为了引用sqrt函数
int main()//主函数
{
  double x1,y1,x2,y2,x3,y3;//定义变量
  float side_Length1,side_Length2,side_Length3;//定义变量
  
  printf("请输入第一个坐标；");//提示语句
  scanf("%lf %lf",&x1,&y1);
  printf("请输入第二个坐标；");//提示语句
  scanf("%lf %lf",&x2,&y2);
  printf("请输入第三个坐标；");//提示语句
  scanf("%lf %lf",&x3,&y3);
  
  side_Length1=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
  side_Length2=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
  side_Length3=sqrt(pow(x3-x2,2)+pow(y3-y2,2));

  if(side_Length1+side_Length2>side_Length3&&side_Length2+side_Length3>side_Length1
  &&side_Length1+side_Length3>side_Length2) //判断条件
  {
    printf("这三个点可以构成三角形！\n");
  }
  else
  {
    printf("这三个点无法构成三角形！\n");
  }
  return 0;//主函数返回值为0
}
