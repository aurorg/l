#include<stdio.h>//头文件
int main()//主函数
{
  void swap(int *p1,int *p2); //函数声明
  int n1,n2,n3;//定义整型变量
  int *p1,*p2,*p3;//定义指针变量
  printf("请输入3个整数：");//提示语句
  scanf("%d %d %d",&n1,&n2,&n3); //键盘录入
  p1=&n1;//将n1的地址赋给指针变量p1
  p2=&n2;
  p3=&n3;
  if(n1>n2)
  {
    swap(p1,p2); //函数调用
  }
  if(n1>n3)
  {
    swap(p1,p3);
  }
  if(n2>n3)
  {
    swap(p2,p3);
  }
  printf("%d %d %d\n",n1,n2,n3);//输出排序后的结果
  return 0;//主函数返回值为0
}
void swap(int *p1,int *p2)//自定义函数
{
  int p;//定义整型变量
  p=*p1; //交换位置
  *p1=*p2;
  *p2=p;
}
