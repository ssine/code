#include<stdio.h>

int main(){
    int N,i,n,j,a,b,c,d;
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        a = 0;
        scanf("%d",&n);
        for(j=2;j*j<=n;j++){
            if(n%j==0){
                if(a){
                    c = j;
                    d = n/j;
                    break;
                }else{
                    a = j;
                    b = n/j;
                }
            }
        }
        printf("Case #%d: %d = %d * %d = %d * %d\n",i,n,a,b,c,d);
    }
    return 0;
}
