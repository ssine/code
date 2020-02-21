#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int pfft[1<<20],pm[1<<20];
void factor(unsigned int);
void init();

int main(){
    freopen(".\\in&outputs\\input47.txt","r",stdin);
    freopen(".\\in&outputs\\output47.txt","w",stdout);
    unsigned int N,i;
    int b,n0,nd;
    double d;
    init();
    while(scanf("%d%d",&N,&b)==2){
        memset(pfft,0,sizeof(pfft));
        for(i=2;i<=N;i++) factor(i);
        if(N==1||N==0) nd = 0;
        else nd = 0.5*log(8*atan(1.0)*N)/log(b)+N*log(N/(exp(1)))/log(b);
        printf("%d %d\n",n0,nd+1);
    }
    return 0;
}

void factor(unsigned int n){
    unsigned int i
    for(i=2;i<=sqrt(n);i++){
        if()
    }
}

void init(){
    int i,j,n=0
    for(i=0;i)
}
