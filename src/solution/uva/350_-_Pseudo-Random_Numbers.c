#include<stdio.h>
#include<string.h>

int main(){
    freopen(".\\in&outputs\\input46.txt","r",stdin);
    freopen(".\\in&outputs\\output46.txt","w",stdout);
    short mk[100002];
    int Z,I,M,L,i,cs=1;
    while(scanf("%d%d%d%d",&Z,&I,&M,&L),Z+I+M+L){
        memset(mk,0,sizeof(mk));
        i=0;
        while(mk[L]==0){
            mk[L] = i;
            L = (Z*L+I)%M;
            i++;
        }
        printf("Case %d: %d\n",cs++,i-mk[L]);
    }
    return 0;
}
