#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    freopen(".\\in&outputs\\input37.txt","r",stdin);
    freopen(".\\in&outputs\\output37.txt","w",stdout);
    char s[1000];
    int i,n,l;
    scanf("%d",&n);
    while(getchar()!='\n');
    for(i=0;i<n;i++){
        gets(s);
        l=strlen(s);
        if(strcmp(s,"1")==0||strcmp(s,"4")==0||strcmp(s,"78")==0){
            printf("+\n");
        }else if(s[l-2]=='3'&&s[l-1]=='5'){
            printf("-\n");
        }else if(s[0]=='9'&&s[l-1]=='4'){
            printf("*\n");
        }else if(s[0]=='1'&&s[1]=='9'&&s[2]=='0'){
            printf("?\n");
        }else{
            printf("?\n");
        }
    }
    return 0;
}
