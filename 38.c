#include<stdio.h>//头文件
#include<string.h>//引入strcmp
 struct people//定义结构体变量
 {
   char name[20];//定义字符数组
   int number;//定义整型变量
 } leader[3]={"li",0,"zhang",0,"sun",0}; /*数组的定义和引用不一样，把姓赋给数组name 把0赋给 shu*/
 int main()//主函数
 {
   int i,j;//定义整型变量
   char leader_name[20];//定义字符数组
   for(i=1;i<10;i++)//for循环，循环9次
   {
     printf("请输入人名\n");//提示语句
     scanf("%s",leader_name);//键盘输入名字
     for(j=0;j<3;j++)
    if(strcmp(leader_name,leader[j].name)==0)//比较两个字符串，如果名字相等
     {
       leader[j].number++;//票数加1
     }
   }
   printf("结果是：\n");//提示语句
   for(i=0;i<3;i++)//for循环
   {
      printf("%s票数：%d\n",leader[i].name,leader[i].number);//输出名字和票数
  }
   return 0;//主函数返回值为0
 }
