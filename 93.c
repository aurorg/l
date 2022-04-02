#include<stdio.h>//头文件
int main()//主函数
{
  void insort(int post[],int n);//函数声明
  int array[11],i;//定义整型变量和数组
  printf("请输入10个数据：\n");//提示语句
  for(i=1;i<=10;i++)
  {
    scanf("%d",&array[i]);//循环输入10个数
  }
  printf("原始顺序：\n");//提示语句
  for(i=1;i<11;i++)
  {
    printf("%5d",array[i]);//输出原来的
  }
  insort(array,10);//调用排序函数
  printf("\n插入数据排序后排序：\n");//提示语句
  for(i=1;i<11;i++)
  {
    printf("%5d",array[i]);//输出排序后的结果
  }
  printf("\n"); //换行
  return 0;//函数返回值为0
}
void insort(int post[],int n)
{
  int i,j;
  for(i=2;i<=n;i++) //数组下标从2开始，是[0]做监视哨,s[1]一个数据无可比性
  {
    post[0]=post[i]; //给监视哨赋值
    j=i-1; //确定要比较元素的最右边位置
    while(post[0]<post[j])
    {
      post[j+1]=post[j]; //数据右移
      j--; //移向左边一个未比较的数
    }
    post[j+1]=post[0]; //在确定的位置插入s[i]
  }
}
