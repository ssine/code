#include<stdio.h>
#include<stdlib.h>

unsigned long long x;

int main(){
    freopen("input6.txt","r",stdin);
    freopen("output6.txt","w",stdout);
    int ini,lmt,tm=1,cas=0;
    while( scanf("%d%d",&ini,&lmt) && ini >= 0 ){
        cas++;
        if(ini == 1) {printf("Case %d: A = %d, limit = %d, number of terms = %d\n",cas,ini,lmt,tm); continue;}
        x = ini;
        while(x!=1&&x<=lmt){
            if(x%2){
                x = 3*x + 1;
                tm++;
            }else{
                x = x/2;
                tm++;
            }
        }
        if(x == 1){
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n",cas,ini,lmt,tm);}else{
            printf("Case %d: A = %d, limit = %d, number of terms = %d\n",cas,ini,lmt,tm-1);
        }
        tm = 1;
    }
    system("pause");
    return 0;
}
