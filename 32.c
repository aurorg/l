#include<stdio.h>//头文件
int main()//主函数
{
  void average(float *p,int n);//函数声明
  void search_Grade(float (*p)[4],int n);//函数声明
  float score[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};//定义浮点型数组
  average(*score,12);//平均成绩
  search_Grade(score,2);//第3个学生的成绩，这里写2是因为按照数组从0开始
  return 0;//主函数返回值为0
}
void average(float *p,int n)//自定义求平均成绩函数
{
  float *p_end;//定义浮点类型指针变量
  float sum=0,aver;//定义浮点型变量
  p_end=p+n-1;//把地址赋给指针变量
  for(;p<=p_end;p++)//for循环，注意第一处分号
  {
    sum=sum+(*p);//总和
  }
  aver=sum/n;//平均分
  printf("平均数是:%f",aver);//输出平均分
  printf("\n");//换行
}
void search_Grade(float (*p)[4],int n)//自定义求第n个学生成绩函数
{
  int i;//定义变量
  printf("第%d个学生的成绩是:",n+1);//输出，注意此处我写的是n+1，数组下标是从0开始的
  for(i=0;i<4;i++)//for循环
  {
    printf("%5.2f ",*(*(p+n)+i));
  }
}
