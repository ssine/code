#include<stdio.h>
#include<string.h>
char s[100];
int l;
int isT(int T){
    int i,j;
    for(i=T;i<l;i+=T){
        for(j=0;j<T;j++){
            if(s[j]!=s[i+j]) return 0;
        }
    }
    return 1;
}

int main(){
    freopen(".\\in&outputs\\input57.txt","r",stdin);
    freopen(".\\in&outputs\\output57.txt","w",stdout);
    int T,i;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        l = strlen(s);
        for(i=1;i<l;i++){
            if(s[i]==s[0] && l%i==0)
                if(isT(i)) break;
        }
        if(T>0) printf("%d\n\n",i);
        else printf("%d\n",i);
    }
    return 0;
}
