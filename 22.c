#include<stdio.h>//头文件
int main()//主函数
{
  int a[10];//定义整型数组，数组的大小为10
  int i;//定义整型变量
  printf("原来的顺序：");
  for(i=0;i<10;i++)//赋值使a[0]~a[9]的值为0~9
  {
    a[i]=i;// 把i的值赋给数组a[i]
    printf("%d ",a[i]);//输出a[i],每个数之间加个空格隔开
  }
  printf("\n");//换行
  printf("逆序排列后：");
  for(i=9;i>=0;i--)//倒序输出
  {
    printf("%d ",a[i]);
  }
  printf("\n");//换行
  return 0;//函数返回值为0
}
