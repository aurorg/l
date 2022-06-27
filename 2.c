#include <stdio.h>
#include <math.h>
int main(){
    double x,y;
    scanf("%lf",&x);
    if(x<0){
        y=x+1;
        if(y>0){
            y=y;
        }
        else{
            y=-y;
        }
    }

    else if(x>=0 && x<=5){
        y=2*x+1;
    }

    else{
        y=sin(x) +5;
    }

    printf("x=%.2lf,y=%.2lf",x,y);
    
    return 0;
    
}
