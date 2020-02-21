#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int count(char s[100000]){
    int i,n=1,ju;
    if(!isalpha(s[0])) n--;
    for(i=0;i<strlen(s);i++){
        if( (!isalpha(s[i])) && isalpha(s[i+1]) ) n++;
    }
    printf("%d\n",n);
}

int main(){
    char st[100000];
        
    freopen("input10.txt","r",stdin);
    freopen("output10.txt","w",stdout);

    int i=0,a;
    while((st[i]=getchar()) != EOF){
        if(st[i]=='\n') {
            count(st);
            memset(st,' ',i);
            i=0;
            continue;
        }else{
            i++;
        }
    }
    //system("pause");
}


