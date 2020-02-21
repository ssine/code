#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    freopen("input14.txt","r",stdin);
    freopen("output14.txt","w",stdout);
    char s[110],s2[110],c;
    int f1,l1,f2,l2,full,lari,ls,ls2,i,j,m,no1,no2;
    scanf("%d",&full);
    getchar();
    for(lari=0;lari<full;lari++){
        i=0; f1=0;l1=0;f2=0;l2=0;
        while(1){
            c=getchar();
            if(c=='\n') break;
            s[i] = c;i++;
            if(c=='<'&&(!f1)) f1=i-1;
            if(c=='<'&&f1) f2=i-1;
            if(c=='>'&&(!l1)) l1=i-1;
            if(c=='>'&&l1) l2=i-1;
        }
        if(f1==f2) f1=0;
        ls=i;
        i=0;
        while(1){
            c=getchar();
            if(c=='\n'||c==EOF) break;
            s2[i] = c;i++;
        }
        i=1;
        while(s2[i+1]!='\0'){
            if(s2[i-1]=='.'&&s2[i]=='.'&&s2[i+1]=='.'){
                m=i-1;
                break;
            }
            i++;
        }
        //输出s
        for(i=0;i<f1;i++) printf("%c",s[i]);
        for(i=f1+1;i<l1;i++) printf("%c",s[i]);
        for(i=l1+1;i<f2;i++) printf("%c",s[i]);
        for(i=f2+1;i<l2;i++) printf("%c",s[i]);
        for(i=l2+1;i<ls;i++) printf("%c",s[i]);
        printf("\n");
        //输出s2
        for(i=0;i<m;i++) printf("%c",s2[i]);
        for(i=f2+1;i<l2;i++) printf("%c",s[i]);
        for(i=l1+1;i<f2;i++) printf("%c",s[i]);
        for(i=f1+1;i<l1;i++) printf("%c",s[i]);
        for(i=l2+1;i<ls;i++) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
