#include<stdio.h>//头文件
int main()//主函数入口
{
  printf(" **** ****\n");//打印第一行
   printf(" ********* *********\n");//打印第二行
   printf("************* *************\n");//打印第三行
   int i,j;//定义变量
   for(i=0;i<3;i++)//打印4-6行，一共3行，因此i小于3
   {
     for(j=0;j<29;j++)//限制每行输出*的个数
     {
      printf("*");//这三行只打印*号，无空格输出
    }
     printf("\n");//打印完一行需要进行换行
  }
  for(i=0;i<7;i++) //打印7-13行，一共7行，因此i小于7
   {
     for(j=0;j<2*(i+1)-1;j++)//这个for循环和下面的for是并列的
     {
      printf(" ");//打印空格
    }
     for(j=0;j<27-i*4;j++)//读者可以带入几个数找出条件
     {
      printf("*");//打印*
    }
     printf("\n");
    }
  for(i=0;i<14;i++)//打印最后一行的*
  {
    printf(" ");//打印空格
  }
   printf("*\n") ;//打印*
 return 0;
}
