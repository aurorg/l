#include<stdio.h>//头文件
int main()//主函数
{
  int number,s,i;//定义变量
  for(number=2;number<1000;number++)//for循环
  {
    //直接从2开始
    s=0;
    for(i=1;i<number;i++)
    {
      //检查i是否是m的因子
      if((number%i)==0)
      {
      //如果是的话
        s=s+i;
      }
      }
    if(s==number)
    {
      printf("%d的因子为：",number);
      for(i=1;i<number;i++)
      {
        if(number%i==0)
        {
          //判断是否是因子，是的话就输出
          printf("%d ",i);
        }
      }
        printf("\n");//换行
      }
    }
  return 0;//主函数返回值为0
}
