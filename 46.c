#include<stdio.h>//头文件
int main()//主函数
{
  char c1='C';//定义为字符类型且赋值
  char c2='h';//定义为字符类型且赋值
  char c3='i';//定义为字符类型且赋值
  char c4='n';//定义为字符类型且赋值
  char c5='a';//定义为字符类型且赋值
    c1=c1+4;//c1字符所对应的ASCII码表值加4
    c2=c2+4;//c2字符所对应的ASCII码表值加4
    c3=c3+4;//c3字符所对应的ASCII码表值加4
    c4=c4+4;//c4字符所对应的ASCII码表值加4
    c5=c5+4;//c5字符所对应的ASCII码表值加4
    printf("翻译后的密码是：%c%c%c%c%c\n",c1,c2,c3,c4,c5);//输出结果
    return 0;//主函数返回值为0
}
