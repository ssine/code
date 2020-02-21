#include<stdio.h>
#include<stdlib.h>

int list[51];

int re(int n);

int main(){
    freopen("input30.txt","r",stdin);
    freopen("output30.txt","w",stdout);
    int N,n,i,j;
    scanf("%d",&N);getchar();
    for(j=0;j<N;j++){
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&list[i]);
        printf("Optimal train swapping takes %d swaps.\n",re(i));
    }
    return 0;
}

int re(int n){
    int i,j,ct=0;
    for(i=0;i<n;i++){
        for(j=0;j<i;j++)
            if(list[j]>list[i]) ct++;
    }
    return ct;
}
