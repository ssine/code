#include<stdio.h>
#include<math.h>

int main(){
    int h,m;
    float dh,dm,d;
    while(scanf("%d:%d",&h,&m),h||m){
        dh = 30*h+0.5*m;
        dm = 6*m;
        d = fabs(dh-dm);
        if(d>180) d = 360-d;
        printf("%.3f\n",d);
    }
    return 0;
}
