#include<stdio.h>
#include<string.h>

char s[1000000],t[1000000];

int main(){
    freopen(".\\in&outputs\\input62.txt","r",stdin);
    freopen(".\\in&outputs\\output62.txt","w",stdout);
    int i,j,ls,lt,flag;
    while(scanf("%s%s",s,t)==2){
        ls = strlen(s);
        lt = strlen(t);
        j = 0;
        for(i=0; i<ls; i++){
            flag = 1;
            for(; j<lt; j++){
                if(s[i]==t[j]){
                    j++;
                    flag = 0;
                    break;
                }
            }
            if(flag) break;
        }
        if(i<ls) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
