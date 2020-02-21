#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXN 100

char a[MAXN][MAXN];
char s[100][100];
int found=0;

int len(int se){
    int i;
    for(i=1;i<100;i++){
        if(s[se][i]=='1') return i-1;
    }
}

void check(int r,int c,int se){
    int i,j,k,ct=1,l,wa;
    i = r;
    j = c;
    found = 0;
    l=len(se);
    //printf("len = %d\n",len(se));
    if(s[se][1]==a[r-1][c-1]){
        //printf("lu\n");
        for(k=1;k<l;k++){
            if(a[r-k][c-k]==s[se][k]) ct++;
        }
        if(ct==l) found = 1;
        else ct=1;
    }
    if(s[se][1]==a[r-1][c]){
        //printf("u\n");
        for(k=1;k<l;k++){
            if(a[r-k][c]==s[se][k]) ct++;
        }
        if(ct==l) found = 1;
        else ct=1;
    }
    if(s[se][1]==a[r-1][c+1]){
        //printf("ru\n");
        for(k=1;k<l;k++){
            if(a[r-k][c+k]!=s[se][k]) ct++;
        }
        if(ct==l) found = 1;
        else ct=1;
    }
    if(s[se][1]==a[r][c+1]){
        //printf("r\n");
        for(k=1;k<l;k++){
            if(a[r][c+k]==s[se][k]) ct++;
        }
        if(ct==l) found = 1;
        else ct=1;
    }
    if(s[se][1]==a[r+1][c+1]){
        //printf("rd\n");
        for(k=1;k<l;k++){
            if(a[r+k][c+k]==s[se][k]) ct++;
        }
        //printf("ct=%d",ct);
        if(ct==l) found = 1;
        else ct=1;
    }
    if(s[se][1]==a[r+1][c]){
        //printf("d\n");
        for(k=1;k<l;k++){
            if(a[r+k][c]==s[se][k]) ct++;
        }
        if(ct==l) found = 1;
        else ct=1;
    }
    if(s[se][1]==a[r+1][c-1]){
        //printf("ld\n");
        for(k=1;k<l;k++){
            if(a[r+k][c-k]==s[se][k]) ct++;
        }
        if(ct==l) found = 1;
        else ct=1;
    }
    if(s[se][1]==a[r][c-1]){
        //printf("l\n");
        for(k=1;k<l;k++){
            if(a[r][c-k]==s[se][k]) ct++;
        }
        if(ct==l) found = 1;
        else ct=1;
    }
}

void run(int r,int c){
    int n,ct,i,j,k,l,m;
    char now;
    scanf("%d",&n);
    getchar();
    for(i=0;i<100;i++)
        for(j=0;j<100;j++)
            s[i][j] = '1';
    for(i=1;i<=n;i++){
        gets(s[i]);
    }
    for(i=1;i<=n;i++){
        j=0;
        while(s[i][j]!='\0'&&s[i][j]!='1'){
            if(isupper(s[i][j])) s[i][j]=tolower(s[i][j]);
            j++;
        }
    }

/*
    printf("start s\n");
    for(i=0;i<11;i++){
        for(j=0;j<=12;j++)printf("%c",s[i][j]);
        printf("\n");
    }
    printf("end\n");
    printf("start a\n");
    for(i=1;i<11;i++){
        printf("line %d\n",i);
        for(j=1;j<=12;j++)printf("%c",a[i][j]);
        printf("\n");
    }
    printf("end\n");
*/
    
    for(ct=1;ct<=n;ct++){
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                if(a[i][j]==s[ct][0]){  /*printf("== %d %d %c\n",i,j,a[i][j]);*/ check(i,j,ct);    }
                if(found) break;
                //else  printf("not found\n");
            }
            if(found) break;
        } 
        if(found){
            found = 0;
            printf("%d %d\n",i,j);
            continue;
        }
    }
}

int main(){
    freopen("input12.txt","r",stdin);
    freopen("output12.txt","w",stdout);
    int m,n,cas,bigi,i,j;
    scanf("%d",&cas);
    //printf("cas=%d\n",cas);
    for(bigi=0;bigi<cas;bigi++){
        for(i=0;i<100;i++)
            for(j=0;j<100;j++)
                a[i][j] = '0';
        scanf("%d%d",&m,&n);
        getchar();
        //printf("%d %d\n",m,n);
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                scanf("%c",&a[i][j]);
                if(isupper(a[i][j])) a[i][j]=tolower(a[i][j]);
            }
            getchar();
        }
        run(m,n);
        if(bigi<cas-1) printf("\n");
    }
    //system("pause");
    return 0;
}
