#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char crwd[100000],inp[100000],fd[100000]={'0'};

void diff(){
    int i,j;
    for(i=0;i<strlen(inp);i++){
        for(j=i+1;j<strlen(inp);j++){
                if(inp[i] == inp[j]) inp[j] = '1';
        }
    }
}

int done(){
    int i,get=0;
    for(i=0;i<strlen(crwd);i++) if(crwd[i]!='0') get=1;
    if(get == 1) return 0;
    else return 1;
}

int main(){
    freopen("input5.txt","r",stdin);
    freopen("output5.txt","w",stdout);
    int rd,count=0,i,j,u=0,find=0,go=1,d;
    while(1){
        scanf("%d\n",&rd);
        if(rd==-1) break;
        gets(crwd);
        gets(inp);
        printf("Round %d\n",rd);
        diff();//去重

        for(i=0;i<strlen(inp);i++){//遍历输入
            u = 0;
            memset(fd,'0',sizeof(fd));
            if(inp[i]=='1') continue;
            for(j=0;j<strlen(crwd);j++) if(fd[j]==inp[i]) continue;
            for(j=0;j<strlen(crwd);j++) {
                if(crwd[j]==inp[i]){
                    fd[u] = crwd[j];
                    crwd[j] = '0';
                    u++;
                    find++;
                }
            }

            if(count == 6&&find == 0){//猜错7次了
                if(done()) {
                    printf("You win.\n");
                }else{
                    printf("You lose.\n");
                }
                go = 0;
            }
            if(find == 0) count ++;
            find = 0;
        }
        count = 0;
        if(go){
            if(done()) printf("You win.\n");
            else printf("You chickened out.\n");
        }
        go = 1;
    }
    return 0;
}
