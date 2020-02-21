#include<stdio.h>
#include<stdlib.h>

int main(){
    //freopen("input3.txt","r",stdin);
    //freopen("output3.txt","w",stdout);
    int num=0,i,n=0;
    char c;
    while((c=getchar()) != EOF){
        if(c>='A'&&c<='Z'){
            for(i=0;i<num;i++) printf("%c",c);
            num = 0;
            continue;
        }
        if(c>='1'&&c<='9'){
            if(n==1){printf("\n");n=0;}
            num += c-48;
            continue;
        }
        if(c == '*'){
            for(i=0;i<num;i++) printf("%c",c);
            num = 0;
            continue;
        }
        if(c == 'b'){
            for(i=0;i<num;i++) printf(" ");
            num = 0;
            continue;
        }
        if(c == '\n'){
            n++;
            if(n>1) {
                printf("\n\n");
                n = 0;
            }
            continue;
        }
        if(c == '!'){
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
