#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int pile[32],all;

void reverse(int f,int t){
    int i,p;
    for(i=f;i<=(f+t)/2;i++){
        p=pile[i];
        pile[i]=pile[t-i+f];
        pile[t-i+f]=p;
    }
    return;
}

void re(int m){
    int i,max=0,p;
    if(m==0) return;
    for(i=0;i<=m;i++) if(pile[i]>max){max=pile[i];p=i;}
    if(pile[m]==max) re(m-1);
    else if(pile[0]==max){
        reverse(0,m);
        if(m!=0) printf("%d ",all-m+1);
        re(m-1);
    }else{
        reverse(0,p);
        if(p!=0) printf("%d ",all-p+1);
        reverse(0,m);
        if(m!=0) printf("%d ",all-m+1);
        re(m-1);
    }
}

int main(){
    freopen("input31.txt","r",stdin);
    freopen("output31.txt","w",stdout);
    int i=0,j,n,k;
    char a,b,c;
    while(1){
        i=0;
        while(1){
            a=getchar();
            b=getchar();
            if(b==' '){
                pile[i++]=a-'0';
            }else if(isdigit(b)){
                pile[i++]=(a-'0')*10+b-'0';
                c=getchar();
                if(c=='\n') break;
                if(c==EOF){
                    for(k=0;k<i-1;k++) printf("%d ",pile[k]);
                    printf("%d\n",pile[k]);
                    all=i-1;
                    re(i-1);
                    printf("0\n");
                    return 0;
                }
            }else{
                pile[i++]=a-'0';
                if(b=='\n') break;
                if(b==EOF){
                    for(k=0;k<i-1;k++) printf("%d ",pile[k]);
                    printf("%d\n",pile[k]);
                    all=i-1;
                    re(i-1);
                    printf("0\n");
                    return 0;
                }
            }
        }
        for(k=0;k<i-1;k++) printf("%d ",pile[k]);
        printf("%d\n",pile[k]);
        all=i-1;
        re(i-1);
        printf("0\n");
    }
}
