#include<stdio.h>//头文件 
#define NEWSIZE 1000//宏定义
char newbuf[NEWSIZE];//定义字符数组
char *newp=newbuf;

char *new(int number) //自定义函数
{
  if(newp+number<=newbuf+NEWSIZE)
  {
    newp+=number;
    return(newp-number);
  }
  else
  {
    return(NULL);
  }
}
