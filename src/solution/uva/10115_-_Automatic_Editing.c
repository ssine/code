#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[260],fd[11][256],rep[11][256];
int f,er=0,flen[11],rlen[11],len;

void find(int n){
    int i,j,ct;
    for(i=0;i<=len-flen[n]+1;i++){
        ct=0;
        for(j=0;j<flen[n];j++){
            if(fd[n][j]==str[i+j]) ct++;
            else break;
        }
        if(ct==flen[n]){
            f=i;
            return;
        }
    }
    er=1;
    return;
}

void replace(int n){
    int i,d;
    if(flen[n]==rlen[n]){
        for(i=0;i<rlen[n];i++)
            str[f+i] = rep[n][i];
    }else if(flen[n]<rlen[n]){
        d = rlen[n]-flen[n];
        for(i=len+d+1;i>=f+flen[n];i--) str[i] = str[i-d];
        for(i=0;i<rlen[n];i++) str[f+i] = rep[n][i];
    }else if(flen[n]>rlen[n]){
        d = flen[n]-rlen[n];
        for(i=0;i<rlen[n];i++) str[f+i] = rep[n][i];
        for(i=f+rlen[n];i<=len-d+2;i++) str[i] = str[i+d];
    }
    return;
}

int main(){
    freopen("input21.txt","r",stdin);
    freopen("output21.txt","w",stdout);
    int i,n;
    while(scanf("%d",&n)==1){
        if(n==0) break;
        memset(str,'\0',sizeof(str));
        getchar();
        for(i=0;i<n;i++){
            gets(fd[i]);
            gets(rep[i]);
        }
        gets(str);
        len = strlen(str);
        for(i=0;i<n;i++){
            flen[i] = strlen(fd[i]);
            rlen[i] = strlen(rep[i]);
            while(1){
                find(i);
                if(er){ er=0; break; }
                else{ replace(i); len=strlen(str); }
                1+1;
            }
        }
        printf("%s\n",str);
    }
    return 0;
}
