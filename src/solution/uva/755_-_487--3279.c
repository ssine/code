#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char tel[100000][200];
char trans[]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9'};

int cmp_str(const void *_a,const void *_b){
    char *a = (char*)_a;
    char *b = (char*)_b;
    return strcmp(a,b);
}

int count(int p){
    int n=0;
    while(strcmp(tel[p],tel[p+n])==0) n++;
    return n;
}

int main(){
    freopen(".\\in&outputs\\input35.txt","r",stdin);
    freopen(".\\in&outputs\\output35.txt","w",stdout);
    int all,i,n,j,p,cn,k;
    char c;
    scanf("%d",&all);
    for(i=0;i<all;i++){
        scanf("%d",&n);
        while(getchar()!='\n');
        for(j=0;j<n;j++){
            p=0;
            while((c=getchar())!='\n'&&c!=EOF){
                if(isdigit(c)) tel[j][p++]=c;
                else if(isupper(c)) tel[j][p++]=trans[c-'A'];
            }
        }
        qsort(tel,n,sizeof(tel[0]),cmp_str);
        int flag = 0;
        for(j=0;j<n;){
            int num = count(j);
            if(num==1){
                j++;
                continue;
            }
            flag = 1;
            for(k=0;k<3;k++) printf("%c",tel[j][k]);
            printf("-");
            for(k=3;k<7;k++) printf("%c",tel[j][k]);
            printf(" %d\n",num);
            j+=num;
        }
        if(flag==0) printf("No duplicates.\n");
        if(i<all-1) printf("\n");
    }
}
