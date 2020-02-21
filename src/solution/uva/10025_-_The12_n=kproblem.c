#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    freopen(".\\in&outputs\\input38.txt","r",stdin);
    freopen(".\\in&outputs\\output38.txt","w",stdout);
    int cases,i;
    long long int k,n;
    double _n;
    scanf("%d",&cases);
    for(i=0;i<cases;i++){
        scanf("%lld",&k);
        if(k<0) k = -k;
        if(k==0){
            printf("3\n");
        }else{
            _n = (sqrt(8*k+1)-1)/2;
            n = (int)floor(_n);
            if(_n==n){
                printf("%lld\n",n);
            }else{
                n++;
                if((n*(n+1)/2)%2==k%2){
                    printf("%lld\n",n);
                }else{
                    if(n%2) printf("%lld\n",n+2);
                    else printf("%lld\n",n+1);
                }
            }
        }
        if(i<cases-1) printf("\n");
    }
    return 0;
}
