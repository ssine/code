#include<stdio.h>

int main(){
    long long a,b;
    char c=127;
    while(scanf("%lld%lld",&a,&b)!=EOF){
        printf("%lld",a>b?a-b:b-a);
            printf("%c",c);
    }
    return 0;
}
