#include<stdio.h>//头文件
#include<string.h>//为了引用strcpy函数
int main(){//主函数
  struct student{  //学生结构体
    int num;
    char name[20];
    char sex;
    float score;
  };
  struct student s_1;//定义结构体变量
  struct student *p;//定义结构体指针变量
  p=&s_1;//将s_1得地址赋给指针变量
  s_1.num=10010;//赋值
  strcpy(s_1.name,"yan");//复制
  s_1.sex='M';//赋值
  s_1.score=100;//赋值
  printf("学号是：%d\n名字是%s\n性别是：%c\n成绩是：%f\n",
  s_1.num,s_1.name,s_1.sex,s_1.score); //输出结果
  printf("--------------------\n"); //隔开
  printf("学号是：%d\n名字是%s\n性别是：%c\n成绩是：%f\n",
  (*p).num,(*p).name,(*p).sex,(*p).score); //输出结果
  return 0;//主函数返回值为0
}
