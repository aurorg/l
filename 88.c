#include<stdio.h>//头文件
int main()//主函数
{
  int i,num;//定义整型变量
  num=2;//赋初值
  for (i=0;i<3;i++)//3层循环
  {
    printf("整型变量num的值是：%d\n",num);
    num++;
    {
    auto int num=1;
    printf("auto类型的num值是：%d\n",num);
    num++;
    }
  }
  return 0;//函数返回值为0
}
