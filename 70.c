#include<stdio.h>//头文件
int main()//主函数
{
  void copy(char s[],char c[]); //函数声明
  char str[80],character[80]; //定义字符数组
  printf("输入字符串：");//提示语句
  gets(str); //键盘录入
  copy(str,character); //调用该函数
  printf("元音字母是：%s\n",character);//输出复制后的字符串
  return 0;//主函数返回值为0
}
void copy(char s[],char character[])//自定义复制函数
{
  int i,j;//定义整型变量
  for(i=0,j=0;s[i]!='\0';i++)//遍历
  {
    //判断是否为元音字母
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
    {
      character[j]=s[i];
      j++;
    }
    else
    { //不符合什么也不输出
      character[j]='\0';
    }
  }
}
