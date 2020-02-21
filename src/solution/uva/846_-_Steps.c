#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    freopen(".\\in&outputs\\input41.txt","r",stdin);
    freopen(".\\in&outputs\\output41.txt","w",stdout);
    int N,s,e,i,d,sq;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d%d",&s,&e);
        d = e-s;
        if(!d){printf("0\n");continue;}
        sq = (int)sqrt(d*1.0);
        if(d==sq*sq) printf("%d\n",2*sq-1);
        else if(d-sq*sq<=sq) printf("%d\n",2*sq);
        else printf("%d\n",2*sq+1);
    }
    return 0;
}
