#include<stdio.h>//头文件
int main()//主函数
{
  int i,j,lower,number,space,other,capital;//定义整型变量
  char text[3][80];//定义字符数组
  capital=0;//赋初值
  lower=0;//赋初值
  number=0;//赋初值
  space=0;//赋初值
  other=0;//赋初值
  for(i=0;i<3;i++)
  { //设置3行
    printf("请随意输入一行：\n"); //注意录入的必须是英文状态下的符号
    gets(text[i]); //gets函数可以录入空格
    for(j=0;j<80&&text[i][j]!='\0';j++)
    {
      if(text[i][j]>='A'&&text[i][j]<='Z')//如果是大写
      {
        capital++;
      }
      else if(text[i][j]>='a'&&text[i][j]<='z')//如果是小写
      {
        lower++;
      }
      else if(text[i][j]>='0'&&text[i][j]<='9')//如果是数字
      {
        number++;
      }
      else if(text[i][j]==' ')//如果是空格
      {
        space++;
      }
      else   //其他
      {
        other++;
      }
    }
  }
  printf("\n输出结果：\n");//提示语句
  printf("大写字母 :%d\n",capital);
  printf("小写字母 :%d\n",lower);
  printf("数字 :%d\n",number);
  printf("空格 :%d\n",space);
  printf("其他字符 :%d\n",other);
  return 0;//主函数返回值为0
}
