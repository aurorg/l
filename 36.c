#include<stdio.h>//头文件
int main()//主函数
{
  int max_Number(int ,int );//函数声明
  int min_Number(int x,int y);//函数声明
  int (*p)(int,int);//定义有参数的函数指针
  int a,b,c,d;//定义整型变量
  printf("请输入两个数:");//提示语句
  scanf("%d,%d",&a,&b);//键盘输入两个数，注意之间用英文逗号隔开
  printf("请选择1或者2：");//提示语句
  scanf("%d",&c);//键盘输入
  if(c==1)//如果是1
  {
    p=max_Number;//调用求大的函数
  }
  else if(c==2)//如果是2
  {
    p=min_Number;//调用求小的函数
  }
  d=(*p)(a,b);//给d赋值
  if(c==1)//如果是1
  {
    printf("max=%d",d);//输出大的
  }
  else
  {
    printf("min=%d",d);//否则输出小的
  }
  return 0; //主函数返回值为0
}
int max_Number(int x,int y)//自定义求两个数中的较大数
{
  return(x>y?x:y); //此处使用了三目运算符
}
int min_Number(int x,int y)//自定义求两个数中的较小数
{
  return (x>y?y:x);//此处使用了三目运算符
}#include<stdio.h>//头文件
int main()//主函数
{
  int max_Number(int ,int );//函数声明
  int min_Number(int x,int y);//函数声明
  int (*p)(int,int);//定义有参数的函数指针
  int a,b,c,d;//定义整型变量
  printf("请输入两个数:");//提示语句
  scanf("%d,%d",&a,&b);//键盘输入两个数，注意之间用英文逗号隔开
  printf("请选择1或者2：");//提示语句
  scanf("%d",&c);//键盘输入
  if(c==1)//如果是1
  {
    p=max_Number;//调用求大的函数
  }
  else if(c==2)//如果是2
  {
    p=min_Number;//调用求小的函数
  }
  d=(*p)(a,b);//给d赋值
  if(c==1)//如果是1
  {
    printf("max=%d",d);//输出大的
  }
  else
  {
    printf("min=%d",d);//否则输出小的
  }
  return 0; //主函数返回值为0
}
int max_Number(int x,int y)//自定义求两个数中的较大数
{
  return(x>y?x:y); //此处使用了三目运算符
}
int min_Number(int x,int y)//自定义求两个数中的较小数
{
  return (x>y?y:x);//此处使用了三目运算符
}
