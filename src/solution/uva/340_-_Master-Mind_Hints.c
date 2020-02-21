#include<stdio.h>
#include<string.h>

int crt[1010],gus[1000][1010],crti[1010];

int all0(int N,int cr){
    int i,ct=0;
    for(i=0;i<N;i++) if(gus[cr][i]==0) ct++;
    if(ct==N) return 1;
    else return 0;
}

int main(){
    freopen("input26.txt","r",stdin);
    freopen("output26.txt","w",stdout);
    int N,num=1,i,j,k,cr,a,b;
    while(scanf("%d",&N),N!=0){
        cr=-1;
        printf("Game %d:\n",num++);
        for(i=0;i<N;i++) scanf("%d",&crt[i]);
        do{
            cr++;
            for(i=0;i<N;i++) scanf("%d",&gus[cr][i]);
        }while(!all0(N,cr));
        for(j=0;j<cr;j++){
            memcpy(crti,crt,N*sizeof(int));
            a=0;b=0;
            for(i=0;i<N;i++){
                if(crti[i]==gus[j][i]){
                    a++;
                    crti[i]=0;
                    gus[j][i]=0;
                    continue;
                }
            }
            for(i=0;i<N;i++){
                if(crti[i]==0) continue;
                for(k=0;k<N;k++)
                    if(crti[i]==gus[j][k]){
                        gus[j][k]=0;
                        b++;
                        break;
                    }
            }
            printf("    (%d,%d)\n",a,b);
        }
    }
    return 0;
}
