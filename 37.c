#include<stdio.h>//头文件
int main()//主函数
{
  struct student_Information   //定义学生结构体
  {
    int num; //学号
    char name[20];//名字
    char sex[20];//性别
    char address[20]; //地址
  }
  student_Information={8888,"闫小林","男生","广州市"};//赋值
  printf("学号是：%d\n",student_Information.num);//输出学号
  printf("姓名是：%s\n",student_Information.name);//输出名字
  printf("性别是：%s\n",student_Information.sex);//输出性别
  printf("住址是：%s\n",student_Information.address);//输出住址
  return 0;//主函数返回值为0
}
