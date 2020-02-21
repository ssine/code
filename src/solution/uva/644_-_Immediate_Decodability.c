#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char code[11][12];

int ptof(int a,int b,int l){
    if(strncmp(code[a],code[b],l*sizeof(char))==0) return 1;
    else return 0;
}

int check(int len){
    int i,l[11],j;
    for(i=0;i<len;i++){
        for(j=0;j<11;j++){
            if(isalnum(code[i][j])&&(!isalnum(code[i][j+1])))
                l[i] = j+1;
        }
    }
    for(i=0;i<len;i++)
        for(j=0;j<len;j++){
            if(j==i) continue;
            if(l[j]>=l[i]) if(ptof(i,j,l[i])) return 1;
        }
    return 0;
}

int main(){
    freopen("input20.txt","r",stdin);
    freopen("output20.txt","w",stdout);
    int i=0,ct=1,j;
    while(gets(code[i])){
        printf("start!\n");
        for(j=0;j<=9;j++) 
        printf("%s\n",code[j]);
        if(code[i][0]=='9'){
            if(check(i)){
                printf("Set %d is not immediately decodable\n",ct);
                ct++;
            }else{
                printf("Set %d is immediately decodable\n",ct);
                ct++;
            }
            memset(code,'\0',sizeof(code));
            i=-1;
        }
        i++;
    }
    system("pause");
    return 0;
}
