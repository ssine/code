#include<stdio.h>
#include<math.h>

int pow2(int);

int main(){
    int y,p,i;
    double res,lim;
    while(scanf("%d",&y),y){
        i=1;res=-5;
        p = y/10-194;
        lim = pow2(p)*log(2.0);
        while(res<lim){
            res = 0.5*log(8*atan(1.0)*i)+i*log(i/exp(1.0));
            i++;
        }
        printf("%d\n",i-2);
    }
    return 0;
}

int pow2(int m){
    int i,p=1;
    for(i=0;i<m;i++) p*=2;
    return p;
}
