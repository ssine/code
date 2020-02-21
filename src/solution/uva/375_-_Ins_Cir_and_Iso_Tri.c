#include<stdio.h>
#include<math.h>

int main(){
    int N,i;
    double h,l,r,t,sum,pi=4*atan(1.0),rt;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        sum = 0;
        scanf("%lf%lf",&l,&h);
        t = tan(atan(2*h/l)/2);
        r = l*t/2;
        rt = (h-2*r)/h;
        while(r>=0.000001){
            sum += 2*pi*r;
            r *= rt;
        }
        printf("%13.6lf\n",sum);
        if(i<N-1) printf("\n");
    }
    return 0;
}
