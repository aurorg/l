#include<stdio.h>//头文件
int main()//主函数
{
  int a[11]={1,4,6,9,13,16,19,28,40,100};//定义整型数组且赋初值
  int t1,t2,num,end,i,j;//定义整型变量
  printf("原来的输出：\n");//提示语句
  for(i=0;i<10;i++)//遍历输出10个数
  {
    printf("%d ",a[i]);
  }
  printf("\n");//换行
  printf("输入要插入的数：\n");//提示语句
  scanf("%d",&num);//键盘录入要插入的数
  end=a[9];//将最后一个数赋值给end
  if(num>end)//先和最后一个数比大小
  {
    a[10]=num;
  }
  else
  {
    //小于的话，依次比较，直到比插入的数大
    for(i=0;i<10;i++)
    {
      if(a[i]>num)
      {
        t1=a[i];
        a[i]=num;
        for(j=i+1;j<11;j++)
        {
          t2=a[j];
          a[j]=t1;
          t1=t2;
        }
        //把要插入的数放到数组中
        break;
      }
    }
  }
  printf("插入之后排序：\n");//提示语句
  for(i=0;i<11;i++)//遍历输出
  {
    printf("%d ",a[i]);
  }
  printf("\n");//换行
  return 0;//主函数返回值为0
}
