#include<stdio.h>//头文件
int main()//主函数
{
  void sort(int **point,int number); //sort排序函数声明
  int i,number,data[20],**point,*pstr[20]; //定义变量
  printf("输入要排序的个数number：");//提示语句
  scanf("%d",&number);//键盘输入
  for(i=0;i<number;i++)
  {
    pstr[i]=&data[i]; //将第i个整数的地址赋予指针数组pstr的第i个元素
  }
  printf("逐个输入这%d个数：",number);//提示语句
  for(i=0;i<number;i++)
  {
    scanf("%d",pstr[i]);//挨个输入要排序的数
  }
  point=pstr;
  sort(point,number);
  printf("\n-------------------\n"); //提示语句
  printf("输出结果：\n");//提示语句
  for(i=0;i<number;i++)
  {
    printf("%d ",*pstr[i]);//输出排序后的结果
  }
  printf("\n");//换行
  return 0;//主函数返回值为0
}
void sort(int **point,int number)//自定义sort排序函数
{
  int i,j,*temp;//定义变量
  for(i=0;i<number-1;i++)
  {
    for(j=i+1;j<number;j++)
    {
      if(**(point+i)>**(point+j))//比较之后交换整数地址
      {
        temp=*(point+i);
        *(point+i)=*(point+j);
        *(point+j)=temp;
      }
    }
  }
}
