#include<stdio.h>//头文件
int main()//主函数
{
  char *month_name[13]={"illegal month","January","February",
  "March","April","May","June","July","August",
  "September","October","November","December"};//定义指针数组
  int number;//定义整型变量
  printf("输入月份：");//提示语句
  scanf("%d",&number);//键盘输入
  if((number<=12)&&(number>=1))//判断条件
  {
       printf("%d",number);//提示语句
    printf("月的英文是%s\n",*(month_name+number));
  }
  else
  {
    printf("它是错误的!\n");
  }
  return 0;//主函数返回值为0
}
