#include<stdio.h>

int main(){
    double ax,ay,bx,by,cx,cy,dx,dy,x,y,dex,dey;
    while(scanf("%lf%lf%lf%lf",&ax,&ay,&bx,&by)==4){
        x = (ax+bx)/2; y = (ay+by)/2;
        dex = (ax-bx)/2; dey = (ay-by)/2;
        cx = x-dey; cy = y+dex;
        dx = x+dey; dy = y-dex;
        printf("%.10lf %.10lf %.10lf %.10lf\n",cx,cy,dx,dy);
    }
    return 0;
}
