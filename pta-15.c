#include<stdio.h>//头文件
int main()//主函数，程序的入口
{
  int i,f1,f2,f3,row; //定义变量
    f1=1,f2=1; //变量初始化
    printf("输入需要输出的行数：");//提示语句
    scanf("%d",&row); //键盘输入行数
    printf("%d\n%d\n",f1,f2); //先输出第一行和第二行
    for(i=1;i<row-1;i++) ///循环控制后row-2行
    {
      f3=f2+f1; //第3行的值是前面两行之和
      printf("%d\n",f3);
      f1=f2; //变量赋值
      f2=f3;
    }
}
