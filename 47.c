#include<stdio.h>//头文件
#define PI 3.141526//宏定义
int main()//主函数
{
  float r,h;//定义半径、高
    float perimeter;//圆周长
    float area;//圆面积
    float sphere_Surface_Area;//圆球表面积
    float sphere_Volume;//圆球体积
    float cylinder_Volume;//圆柱体积
  printf("输入圆半径r，圆柱高h：");//提示语句
  scanf("%f %f",&r,&h);//键盘输入半径和高
  perimeter=2*PI*r;//周长
  area=PI*r*r;//面积
  sphere_Surface_Area=4*PI*r*r;//圆球表面积
  sphere_Volume=4/3*PI*r*r*r;//圆球体积
  cylinder_Volume=(PI*r*r)*h;//圆柱体积
  printf("周长=%3.1f\n",perimeter);
  printf("圆面积=%3.1f\n",area);
  printf("圆球表面积=%3.1f\n",sphere_Surface_Area);
    printf("圆球体积=%3.1f\n",sphere_Volume);
    printf("圆柱体积=%3.1f\n",cylinder_Volume);
  return 0; //主函数返回值为0
}
