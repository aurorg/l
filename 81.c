#include<stdio.h>//头文件
#include<string.h>
#define LINEMAX 20 //定义字符串的最大长度
int main()
{
  void sort(char **point);//函数声明
  int i;//定义整型变量
  char **point,*pstr[5],str[5][LINEMAX];//定义变量
  for(i=0;i<5;i++)
  {
    pstr[i]=str[i]; //将第i个字符串的首地址赋予指针数组pstr的第i个元素
  }
  printf("输入五个字符串：\n");//提示语句
  for(i=0;i<5;i++)
  {
    scanf("%s",pstr[i]);
  }
  point=pstr;
  sort(point);//调用sort函数
  printf("————————————\n");//提示语句
  printf("输出排序后的结果：\n");//提示语句
  for(i=0;i<5;i++)
  {
    printf("%s\n",pstr[i]);
  }
  return 0;//主函数返回值为0
}
void sort(char **point)//冒泡排序算法实现
{
    int i,j;//定义整型变量
  char *temp;//定义字符指针变量
  for(i=0;i<5;i++)
  {
    for(j=i+1;j<5;j++)
    {
      if(strcmp(*(point+i),*(point+j))>0)//比较后交换字符串地址
      {
        temp=*(point+i);
        *(point+i)=*(point+j);
        *(point+j)=temp;
      }
    }
  }
}
