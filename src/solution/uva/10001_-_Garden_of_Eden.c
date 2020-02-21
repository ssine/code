#include<stdio.h>
#include<stdlib.h>
int gnrt(int);
int isok(short,short);
short rull[2][8],product[35];
int RN[2],N;
char aim[34];

int main(){
    freopen(".\\in&outputs\\input55.txt","r",stdin);
    freopen(".\\in&outputs\\output55.txt","w",stdout);
    int r,i;
    while(scanf("%d",&r)==1){
        int flag=1;
        RN[0]=0;RN[1]=0;
        scanf("%d",&N);
        scanf("%s",&aim[1]);
        for(i=0;i<8;i++){
            if(r&1<<i) rull[1][RN[1]++] = i;
            else rull[0][RN[0]++] = i;
        }
        for(i=0;i<RN[aim[N]-'0'];i++){
            product[0]=rull[aim[N]-'0'][i];
            if(gnrt(1)){
                printf("REACHABLE\n");
                flag=0;
                break;
            }
        }
        if(flag) printf("GARDEN OF EDEN\n");
    }
    return 0;
}

int gnrt(int n){
    if(n==N+1){
        if(product[N]==product[0]) return 1;
        else return 0;
    }
    int i,d=aim[n]-'0';
    for(i=0;i<RN[d];i++){
        if(isok(product[n-1],rull[d][i])){
            product[n] = rull[d][i];
            if(gnrt(n+1)) return 1;
        }
    }
    return 0;
}

int isok(short s1,short s2){
    if(((s1&1) == ((s2&2)>>1)) && ((s1&2)==((s2&4)>>1))) return 1;
    else return 0;
}
