#include<stdio.h>//头文件
int main()//主函数
{
  char i,j,k;//定义字符变量
  for(i='x';i<='z';i++)//i是a的对手；j是b的对手；k是c的对手
  {
    for(j='x';j<='z';j++)
    {
      if(i!=j)
      {
        for(k='x';k<='z';k++)
        {
          if(i!=k&&j!=k)
          {
            if(i!='x'&&k!='x'&&k!='z')
            {
              printf("A--%c\nB--%c\nC--%c\n",i,j,k);//输出结果
            }
          }
        }
      }
    }
  }
  return 0;//主函数返回值为0
}
