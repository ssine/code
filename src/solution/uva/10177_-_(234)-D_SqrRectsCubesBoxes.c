#include<stdio.h>

int main(){
    long long int re,n,s2,t,re2;
    while(scanf("%lld",&n)==1){
        re = n*(n+1)/2;
        re2 = re*re;
        s2 = re*(2*n+1)/3;
        t = n*(n+1)*(2*n+1)*(3*n*n+3*n-1)/30;
        printf("%lld %lld %lld %lld ",s2,re2-s2,re2,re2*(re-1));
        printf("%lld %lld\n",t,re2*re2-t);
    }
    return 0;
}
