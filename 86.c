#include <stdio.h>//头文件
int main()//主函数
{
  long individual;//个位
  long ten; //十
  long thousand;//千
  long ten_Thousand;//万
  long number;
  printf("请输入要判断的数："); //提示语句
  scanf("%ld",&number);
  ten_Thousand=number/10000;
  thousand=number%10000/1000;
  ten=number%100/10;
  individual=number%10;
  if (individual==ten_Thousand&&ten==thousand)//个位等于万位并且十位等于千位
  {
    printf("%d是回文数！\n",number);
  }
  else
  {
    printf("%d不是回文数！\n",number);
  }
  return 0;//主函数返回值为0
}
