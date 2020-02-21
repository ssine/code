#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char cty[2005][76],name[2005][71];
int sp[2001],fw[2001];

int cmp_char(const void* _a,const void* _b){
    char* a = (char*)_a;
    char* b = (char*)_b;
    return *a - *b;
}

int cmp_string(const void* _a,const void* _b){
    char* a = (char*)_a;
    char* b = (char*)_b;
    return strcmp(a,b);
}

void print(int p){
    int i;
    for(i=fw[p];i<=sp[p];i++)
        printf("%c",cty[p][i]);
    return;
}

int dcmp(int p){
    int a;
    if(strncmp(&cty[p][fw[p]],&cty[p-1][fw[p]],(sp[p]-fw[p]+1)*sizeof(char))==0) a=0;
    else a=1;
    return a;
}

int main(){
    freopen("input27.txt","r",stdin);
    freopen("output27.txt","w",stdout);
    int all,i,j,ct=1,n;
    scanf("%d",&all);
    getchar();
    for(i=0;i<all;i++){
        scanf("%s",cty[i]);
        n=strlen(cty[i]);
        gets(&cty[i][n]);
    }
    qsort(cty,all,sizeof(cty[0]),cmp_string);
    for(i=0;i<all;i++){
        for(j=0;j<72;j++){
            if(isalpha(cty[i][j])){
                fw[i]=j;
                break;
            }
        }
        for(j=0;j<72;j++){
            if(isalpha(cty[i][j])&&!isalpha(cty[i][j+1])){
                sp[i]=j;
                break;
            }
        }
    }
    strcpy(cty[i],"## #");
    sp[i] = 1;
    fw[i] = 0;

    print(0);
    for(i=1;i<=all;i++){
        if(dcmp(i)){
            printf(" %d\n",ct);
            if(cty[i][0]!='#'){
                print(i);
            }
            ct=1;
            continue;
        }
        if(cty[i]==cty[i-1]) continue;
        else ct++;
    }
    return 0;
}
