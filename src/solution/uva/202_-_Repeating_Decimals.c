#include<stdio.h>
#include<stdlib.h>
int prd[10000],gi;
int rem[10000],st;
int rept(){
    int i;
    for(i=0;i<gi-1;i++){
        if(rem[i]==rem[gi-1]){
            st = i+1;
            return 1;
        }
    }
    return 0;
}

int main(){
    freopen(".\\in&outputs\\input61.txt","r",stdin);
    freopen(".\\in&outputs\\output61.txt","w",stdout);
    int nu,de,inte,di,_nu,i=0;
    while(scanf("%d%d",&nu,&de)==2){
        gi = 0; _nu = nu;
        inte = nu/de;
        nu -= de*inte;
        while(!rept()){
            di = nu/de;
            rem[gi] = nu - de*di;
            prd[gi++] = di;
            nu = rem[gi-1]*10;
        }
        printf("%d/%d = %d.",_nu,de,inte);
        for(i=1;i<st&&i<51;i++) printf("%d",prd[i]);
        if(st<51){
            printf("(");
            for(i=st;i<gi&&i<51;i++) printf("%d",prd[i]);
            if(gi>50) printf("...)");
            else printf(")");
        }
        printf("\n   %d = number of digits in repeating cycle\n\n",gi-st);
    }
    return 0;
}
