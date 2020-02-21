#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct index {
    char idx[100];
    int p;
    int f;
    int t;
};
struct index id[3000];
char ign[55][11],title[201][1000];
int ignl[55],ignorn,curp=0;

int isignor(int p,int f,int t){
    for(int i=0;i<ignorn;i++){
        if(ignl[i]==t-f+1){
            if(ign[i][0]==title[p][f]){
                if(strncmp(ign[i],&title[p][f],ignl[i]*sizeof(char))==0)
                    return 0;
            }
        }
    }
    return 1;
}

void store(int pst,int f,int t){
    strncpy(id[curp].idx,&title[pst][f],(t-f+1)*sizeof(char));
    //sprintf(id[curp].idx+strlen(id[curp].idx),"0000000000000%c",curp);
    id[curp].p = pst;
    id[curp].f = f;
    id[curp].t = t;
    curp++;
    return;
}

int cmp_id(const void *_a,const void *_b){
    struct index *a = (struct index*)_a;
    struct index *b = (struct index*)_b;
    int cm = strcmp(a->idx,b->idx);
    if(cm==0){
        if((a->p) > (b->p)) return 1;
        else if((a->p) < (b->p)) return -1;
        else if((a->f) > (b->f)) return 1;
        else return -1;
    }
    return cm;
}

int main(){
    freopen("input34.txt","r",stdin);
    freopen("output34.txt","w",stdout);
    int i=0,titlen,j,f,t;
    while(scanf("%s",ign[i])==1){
        if(ign[i][0]==':') break;
        ignl[i] = strlen(ign[i]);
        i++;
    }
    ignorn = i;
    i = 0;
    getchar();
    while(gets(title[i])) i++;
    titlen = i;
    for(i=0;i<titlen;i++){
        f=0;t=0;
        for(j=0;j<strlen(title[i]);j++){
            title[i][j] = tolower(title[i][j]);
            if(isalpha(title[i][j])&&!isalpha(title[i][j-1])) f=j+1;
            if(isalpha(title[i][j])&&!isalpha(title[i][j+1])) t=j+1;
            if(f&&t){
                if(isignor(i,f-1,t-1)) store(i,f-1,t-1);
                f=0;t=0;
            }
        }
    }
    qsort(id,curp,sizeof(id[0]),cmp_id);
    for(i=0;i<curp;i++){
        int p = id[i].p;
        for(j=0;j<id[i].f;j++) printf("%c",title[p][j]);
        for(;j<=id[i].t;j++) printf("%c",toupper(title[p][j]));
        for(;j<strlen(title[p]);j++) printf("%c",title[p][j]);
        printf("\n");
    }
    return 0;
}
