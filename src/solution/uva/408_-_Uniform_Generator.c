#include<stdio.h>

int main(){
    freopen(".\\in&outputs\\input45.txt","r",stdin);
    freopen(".\\in&outputs\\output45.txt","w",stdout);
    int a[100005],S,M,i;
    a[0]=0;
    while(scanf("%d%d",&S,&M)==2){
        i=1;
        do{
            a[i] = (a[i-1]+S)%M;
            i++;
        }while(a[i-1]);
        if(i==M+1) printf("%10d%10d    Good Choice\n\n",S,M);
        else printf("%10d%10d    Bad Choice\n\n",S,M);
    }
    return 0;
}
