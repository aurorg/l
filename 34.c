#include<stdio.h>//头文件
int main()//主函数
{
  char a[]="I love you";//定义字符数组且赋初值
  char b[20];//定义字符数组
  int i;//定义整型变量
  for(i=0;*(a+i)!='\0';i++)//for循环，!='\0'是指最后一个字符不是\0
  {
    *(b+i)=*(a+i);//赋值
  }
  *(b+i)='\0';//赋值
  printf("字符串a是:%s\n",a);//输出原来的
  printf("单个输出字符b："); //提升语句
  for(i=0;b[i]!='\0';i++)//for循环
  {
    printf("%c",b[i]);//输出字符数组
  }
  printf("\n");//换行
  return 0;//主函数返回值为0
}
