#include<stdio.h>
#include<string.h>

int main(){
    int T,cur,s;
    char c;
    scanf("%d",&T); getchar();
    while(T--){
        s=0; cur=0;
        while((c=getchar())!='\n'){
            if(c=='O'){
                cur++;
                s += cur;
            }else cur=0;
        }
        printf("%d\n",s);
    }
    return 0;
}
