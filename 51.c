#include<stdio.h>//头文件
int main()//主函数
{
  int height=10; //定义灯塔高度
  float x1=2,x2=-2,x3=-2,x4=2,y1=2,y2=2,y3=-2,y4=-2;//定义坐标
  float x,y,d1,d2,d3,d4;//定义坐标
  printf("请输入一个点坐标（x,y）：");//提示语句
  scanf("%f,%f",&x,&y);//键盘输入坐标
  d1=(x-x4)*(x-x4)+(y-y4)*(y-y4);//求该点到各中心点距离
  d2=(x-x1)*(x-x1)+(y-y1)*(y-y1);//求该点到各中心点距离
  d3=(x-x2)*(x-x2)+(y-y2)*(y-y2);//求该点到各中心点距离
  d4=(x-x3)*(x-x3)+(y-y3)*(y-y3);//求该点到各中心点距离
  if(d1>1&&d2>1&&d3>1&&d4>1)//判断该点是否在塔外
  {
    height=0;
  }
  printf("该点的高度为%d\n",height);
  return 0;//主函数返回值为0
}