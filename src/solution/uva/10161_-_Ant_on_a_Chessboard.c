#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){
    freopen("input22.txt","r",stdin);
    freopen("output22.txt","w",stdout);
    int n,l,a;
    unsigned int u,d;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        getchar();
        a = floor(sqrt(n));
        if(a*a==n){ printf("%d %d\n",a%2?1:a,a%2?a:1); continue; }
        l = a*a;
        u = (a+1)*(a+1);
        d = (l+1+u)/2;
        if(a%2==0){
            if(n<d) printf("%d %d\n",a+1,n-l);
            else if(n>d) printf("%d %d\n",u-n+1,a+1);
            else printf("%d %d\n",a+1,a+1);
        }else{
            if(n<d) printf("%d %d\n",n-l,a+1);
            else if(n>d) printf("%d %d\n",a+1,u-n+1);
            else printf("%d %d\n",a+1,a+1);
        }
    }
    return 0;
}
