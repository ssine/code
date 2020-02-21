#include<stdio.h>

int main(){
    freopen(".\\in&outputs\\input44.txt","r",stdin);
    freopen(".\\in&outputs\\output44.txt","w",stdout);
    int n,i,re;
    while(scanf("%d",&n)==1){
        re = 1;
        for(i=1;i<=n;i++){
            re = re%100000;
            re *= i;
            while(re%10==0) re/=10;
        }
        printf("%5d -> %d\n",n,re%10);
    }
    getchar();
    return 0;
}
