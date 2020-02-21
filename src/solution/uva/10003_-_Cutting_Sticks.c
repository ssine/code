#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int d[60][60],cut[60];
int max;
int dp(int,int);

int main(){
    freopen(".\\in&outputs\\input56.txt","r",stdin);
    freopen(".\\in&outputs\\output56.txt","w",stdout);
    int n,l,i,j;
    while(scanf("%d",&l),l){
        scanf("%d",&n);
        memset(d,-1,sizeof(d));
        max = n*l;
        cut[0] = 0;
        for(i=1;i<=n;i++) scanf("%d",&cut[i]);
        cut[n+1] = l;
        for(i=0;i<=n;i++) d[i][i+1] = 0;
        printf("The minimum cutting is %d.\n",dp(0,n+1));
    }
    return 0;
}

int dp(int s,int e){
    if(d[s][e]!=-1) return d[s][e];
    int i,min=max,curl;
    for(i=s+1;i<e;i++){
        curl = dp(s,i)+dp(i,e);
        if(curl<min) min = curl;
    }
    min = min + cut[e] - cut[s];
    d[s][e] = min;
    return min;
}
