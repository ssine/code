#include<stdio.h>
#include<stdlib.h>

int main(){
    freopen("input15.txt","r",stdin);
    freopen("output15.txt","w",stdout);
    char c,p,l;
    int cas,cur;
    double P,U,I,pc,uc,ic;
    scanf("%d",&cas);
    getchar();
    for(cur=1;cur<=cas;cur++){
        pc=0;ic=0;uc=0;
        printf("Problem #%d\n",cur);
        while(1){
            c=getchar();
            if(c=='='){
                switch(p){
                    case 'U': scanf("%lf%c",&U,&l); uc=1; if(l=='m') U*=0.001;if(l=='k') U*=1000;if(l=='M') U*=1000000; break;
                    case 'P': scanf("%lf%c",&P,&l); pc=1; if(l=='m') P*=0.001;if(l=='k') P*=1000;if(l=='M') P*=1000000; break;
                    case 'I': scanf("%lf%c",&I,&l); ic=1; if(l=='m') I*=0.001;if(l=='k') I*=1000;if(l=='M') I*=1000000; break;
                }
            }
            if(c=='\n'||c==EOF) break;
            p=c;
        }
        if(!uc) printf("U=%.2fV\n\n",P/I);
        if(!pc) printf("P=%.2fW\n\n",U*I);
        if(!ic) printf("I=%.2fA\n\n",P/U);
    }
    return 0;
}
