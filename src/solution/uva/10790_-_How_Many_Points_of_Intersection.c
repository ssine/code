#include<stdio.h>

int main(){
    int n=1;
    long long int a,b,p;
    while(scanf("%lld%lld",&a,&b),a+b){
        p = b*(b-1)*a*(a-1)/4;
        printf("Case %d: %lld\n",n++,p);
    }
    return 0;
}
