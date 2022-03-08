#include<stdio.h>//头文件
struct student //定义学生结构体
{
  int num; //学号
  float score;//成绩
  struct student *next;
};
int main()//主函数
{
  struct student a,b,c;//定义结构体变量
  struct student *head,*point;//定义结构体指针变量
  a.num=10101;//学号赋值
  a.score=89.5;//成绩赋值
  b.num=10103;//学号赋值
  b.score=90.0;//成绩赋值
  c.num=10107;//学号赋值
  c.score=85.0;//成绩赋值
  head=&a;//将第1个结点的起始地址赋给头指针head
  a.next=&b;//将第2个结点的起始地址赋给第1个结点的next成员
  b.next=&c;//将第3个结点的起始地址赋给第2个结点的next成员
  c.next=NULL;//第3个结点的next成员赋给null
  point=head;
  do   //do while循环
  {
    printf("%ld %5.1f\n",point->num,point->score);//输出结果
    point=point->next;
  }
  while(point!=NULL);
  return 0;//主函数返回值为0
}
