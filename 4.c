#include<stdio.h>
int main(void)
{
char c;
c=getchar();
while(c!='\n'){
if(c=='-') printf("fu");
else if(c=='0') printf("ling");
else if(c=='1') printf("yi");
else if(c=='2') printf("er");
else if(c=='3') printf("san");
else if(c=='4') printf("si");
else if(c=='5') printf("wu");
else if(c=='6') printf("liu");
else if(c=='7') printf("qi");
else if(c=='8') printf("ba");
else if(c=='9') printf("jiu");
c=getchar();
if(c!='\n')
printf(" ");
}
return 0;
}