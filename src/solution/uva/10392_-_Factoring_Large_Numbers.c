#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

long long root(long long a){
    long long i;
    for(i=2;i<a;i++){
        if(i*i>=a) return i;
    }
}

int main(){
    freopen("input9.txt","r",stdin);
    freopen("output9.txt","w",stdout);
    long long a,i,rt;
    while(scanf("%I64d",&a)&&a>0){
        //rt = root(a);
        //printf("%lld %lld",a%5,rt);
        for(i=2;i<=a/2;i++){
            while(a%i == 0){
                a = a/i;
                printf("    %lld\n",i);
            }
        }
        if(a!=1) printf("    %lld\n",a);
        printf("\n");
    }
    return 0;
}
