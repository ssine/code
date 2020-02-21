#include<stdio.h>
#include<stdlib.h>
int main(){
    char st[5000000];
    int i=0,j;
    while((st[i]=getchar())!=EOF){
        i++;
    }
    for(j=0;j<=i;j++){
        if(st[j]=='\n') continue;
        else st[j] -= 7;
    } 
    printf("%s",st);
   // system("pause");
}
