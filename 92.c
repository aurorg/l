#include<stdio.h>//头文件
int main()//主函数
{
  void shsort(int s[],int n); //函数声明
  int array[11],i;//定义数组和整型变量
  printf("请输入10个数：\n");//提示语句
  for(i=1;i<=10;i++)
  {
    scanf("%d",&array[i]); //键盘输入10个数
  }
  printf("初始顺序：\n");//提示语句
  for(i=1;i<11;i++)
  {
    printf("%5d",array[i]);//输出键盘输入的10个数
  }
  shsort(array,10);//调用排序函数
  printf("\n排序后顺序：\n");//提示语句
  for(i=1;i<11;i++)
  {
    printf("%5d",array[i]);//输出排序后的10个数
  }
  printf("\n"); //换行
  return 0;//函数返回值为0
}
void shsort(int s[],int n)
{
  int i,j,d;
  d=n/2;
  while(d>=1) //确定固定增量值
  {
    for(i=d+1;i<=n;i++) //数组下标从d+1开始进行直接插入排序
    {
      s[0]=s[i]; //设置监视哨
      j=i-d; //确定要比较元素的最右边位置
      while((j>0)&&(s[0]<s[j]))
      {
        s[j+d]=s[j]; //数据右移
        j=j-d; //向左移d个位置
      }
      s[j+d]=s[0]; //在确定的位置插入s[i]
    }
    d=d/2; //增量变为原来的一半
  }
}
