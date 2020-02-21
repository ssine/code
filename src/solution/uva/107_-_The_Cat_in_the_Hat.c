#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    freopen(".\\in&outputs\\input39.txt","r",stdin);
    freopen(".\\in&outputs\\output39.txt","w",stdout);
    double H,N,n,x,dsq;
    scanf("%lf%lf",&H,&x);
    while(H!=0&&x!=0){
        if(H==1&&x==1){
            printf("0 1\n");
        }else{
            n=0;
            do{
                n++;
                dsq = pow(H,1/n)-pow(x,1/n)-1;
            }while(fabs(dsq)>0.0001);
            N = floor(pow(x,1/n)+0.5);
            n = n+1;
            if(fabs(N-1)<0.0001) printf("%0.lf %.0lf\n",n-1,H*(N+1-(pow(N,n))/(pow(N+1,n-1))));
            else printf("%.0lf %.0lf\n",(1-pow(N,n-1))/(1-N),H*(N+1-(pow(N,n))/(pow(N+1,n-1))));
        }
        if(scanf("%lf%lf",&H,&x)!=2) break;
    }
    return 0;
}
