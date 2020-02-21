#include<stdio.h>
#include<math.h>

int main(){
    freopen(".\\in&outputs\\input43.txt","r",stdin);
    freopen(".\\in&outputs\\output43.txt","w",stdout);
    unsigned int n,sq;
    while(scanf("%d",&n),n){
        sq = sqrt(n);
        if(sq*sq==n) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
