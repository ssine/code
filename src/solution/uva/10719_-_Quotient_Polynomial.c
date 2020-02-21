#include<stdio.h>
#include<string.h>

int main(){
    freopen(".\\in&outputs\\input42.txt","r",stdin);
    freopen(".\\in&outputs\\output42.txt","w",stdout);
    int p[10005],q[10004],i,k,n,t,j;
    char s[200000],*sp;
    p[0]=0;q[0]=0;
    while(scanf("%d",&k)==1){
        while(getchar()!='\n');
        gets(&s[1]);
        i=1;
        for(j=1;j<strlen(&s[1])+1;j++){
            if((s[j-1]==' '||s[j-1]=='\0')&&s[j]!=' '){
                sscanf(&s[j],"%d",&p[i]);
                i++;
            }
        }
        p[i]=0;
        n = i-1;
        printf("q(x):");
        for(i=1;i<=n;i++) q[i]=k*q[i-1]+p[i];
        for(i=1;i<n;i++) printf(" %d",q[i]);
        printf("\nr = %d\n\n",q[i]);
    }
}
