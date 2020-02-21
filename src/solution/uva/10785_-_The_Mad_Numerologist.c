#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char dicc[30]={'J','S','B','K','T','C','L','D','M','V','N','W','F','X','G','P','Y','H','Q','Z','R'},dicv[10]={'A','U','E','O','I'},name[300],sorted[30];

int cmp_char(const void* _a,const void* _b){
    char* a = (char*)_a;
    char* b = (char*)_b;
    return *a - *b;
}

int main(){
    
    freopen("input8.txt","r",stdin);
    freopen("output8.txt","w",stdout);

    int i,j,n,ca,c,v,k,cc=0,vc=0;
    char prc[300],prv[300];
    scanf("%d",&ca);
    for(i=1;i<=ca;i++){//大循环
        memset(prc,'Z',sizeof(prc));//初始化
        memset(prv,'Z',sizeof(prv));
        cc=0;vc=0;
        scanf("%d",&n);
        c = n/2;
        v = (n+1)/2;
        k=0;
        for(j=0;j<c;j++){
            prc[j] = dicc[k];
            cc ++;
            if(cc == 5) {k++; cc = 0;}
        }
        k=0;
        for(j=0;j<v;j++){
            prv[j] = dicv[k];
            vc ++;
            if(vc == 21){k++ ; vc = 0;}
        }
        qsort(prv,v,sizeof(char),cmp_char);//按字典序排序
        qsort(prc,c,sizeof(char),cmp_char);
        v=0;c=0;
        for(j=0;j<n;j++){
            if(j%2) name[j] = prc[c++];
            else name[j] = prv[v++];
        }

        printf("Case %d: ",i);
        for(k=0;k<n;k++) printf("%c",name[k]);
        printf("\n");
    }
    return 0;
}
