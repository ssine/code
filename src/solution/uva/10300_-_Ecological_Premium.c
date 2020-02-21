#include<stdio.h>
#include<stdlib.h>

int main(){
    int tc,fa,i,j;
    long long a,b,c,tot=0;
    scanf("%d",&tc);
    for(i=0;i<tc;i++){
        scanf("%d",&fa);
        for(j=0;j<fa;j++){
            scanf("%lld%lld%lld",&a,&b,&c);
           // printf("%lld",tot);
            tot += a*c;
        }
        printf("%lld\n",tot);
        tot = 0;
    }
   // system("pause");
}
