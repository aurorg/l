#include<stdio.h>//头文件
#include<string.h> //导入库函数
int main()//主函数
{
  void insert(char str[]);//函数声明
  char str[80];//定义字符数组
  printf("输入一个4位数字：");//提示语句
  scanf("%s",str);//因为str是数组，取地址&可以不加
  insert(str);//调用insert函数
  return 0;//主函数返回值为0
}
void insert(char str[])//自定义函数
{
  int i;//定义整型变量
  for(i=strlen(str);i>0;i--)//strlen可以求字符串的长度
  {
    str[2*i]=str[i];
    str[2*i-1]=' ';
  }
  printf("输出结果：%s\n",str);//输出结果
}
