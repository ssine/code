#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char key[22][22],exc[22][75],frm[22][75],ct[22],lk[22];

void lower(int n){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<70;j++){
            if(exc[i][j]=='\0') break;
            frm[i][j]=tolower(exc[i][j]);
        }
}

void comp(int n,int f,int t,int n1){
    int i,d,j,c;
    d=t-f+1;
    for(i=0;i<n1;i++){
        if(lk[i]==d){
            c=0;
            for(j=0;j<lk[i];j++)
                if(frm[n][f+j]==key[i][j]) c++;
            if(c==d) ct[n]++;
        }
    }
}

int check(int n,int n1){
    int i,j,k,f=1,t=0;
    for(i=0;i<70;i++){
        if(!isalpha(frm[n][i])&&isalpha(frm[n][i+1])) f=i+1;
        if(isalpha(frm[n][i])&&!isalpha(frm[n][i+1])) t=i;
        if(f&&t){
            comp(n,f,t,n1);
            f=0; t=0;
        }
    }
}

int main(){

    freopen("input17.txt","r",stdin);
    freopen("output17.txt","w",stdout);

    int i,n1,n2,max,vol=1;
    char c;

    while(scanf("%d%d",&n1,&n2)!=EOF){
        printf("Excuse Set #%d\n",vol++);
        max=0;
        getchar();
        for(i=0;i<n1;i++) gets(key[i]);
        for(i=0;i<n2;i++) gets(exc[i]);
        for(i=0;i<n1;i++) lk[i]=strlen(key[i]);
        for(i=0;i<n2;i++) ct[i]=0;
        lower(n2);
        for(i=0;i<n2;i++) ct[i]==check(i,n1);
        for(i=0;i<n2;i++) if(ct[i]>=max) max=ct[i];
        for(i=0;i<n2;i++) if(ct[i]==max) printf("%s\n",exc[i]);
        printf("\n");
        
    }
    return 0;
}
