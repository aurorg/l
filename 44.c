#include<stdio.h>//头文件
#include <stdlib.h>
int main()
{
  FILE *fp;//定义file类型指针变量
  char ch,filename[10];//定义字符和字符数组
  printf("请输入所用的文件名:");//提示语句
  scanf("%s",filename);//键盘输入
  if((fp=fopen(filename,"w"))==NULL)//w是指只允许写内容
  {
    printf("无法打开此文件\n");//提示语句
    exit(0);//结束程序
  }
  ch=getchar();
  printf("请输入一个准备存储到磁盘的字符串（以#结束）：");//提示语句
  ch=getchar();
  while(ch!='#')//字符结尾不是#时
  {
    fputc(ch,fp);
    putchar(ch);
    ch=getchar();
  }
  fclose(fp);
  putchar(10);
  return 0;//主函数返回值为0
}
