#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct team{
    char name[31];
    int totpnt;
    int goal_in;
    int goal_agst;
    short win;
    short tie;
    short lose; 
} tem[31];
int namelen[31];

void store(char *s,int f1,int f2,int f3,int l,int nt){
    int i,j,a,b;
    sscanf(&s[f1+1],"%d",&a);
    sscanf(&s[f2+1],"%d",&b);
    for(i=0;i<nt;i++){
        if(strncmp(s,tem[i].name,f1)==0&&f1==namelen[i]){
            for(j=0;j<nt;j++){
                if(strcmp(&s[f3+1],tem[j].name)==0){
                    if(a>b){
                        (tem[i].totpnt)+=3;
                        (tem[i].goal_in)+=a;
                        (tem[i].goal_agst)+=b;
                        (tem[i].win)++;
                        (tem[j].goal_in)+=b;
                        (tem[j].goal_agst)+=a;
                        (tem[j].lose)++;
                    }else if(a<b){
                        (tem[j].totpnt)+=3;
                        (tem[i].goal_in)+=a;
                        (tem[i].goal_agst)+=b;
                        (tem[j].win)++;
                        (tem[j].goal_in)+=b;
                        (tem[j].goal_agst)+=a;
                        (tem[i].lose)++;
                    }else{
                        (tem[i].totpnt)++;
                        (tem[j].totpnt)++;
                        (tem[i].goal_in)+=a;
                        (tem[i].goal_agst)+=b;
                        (tem[j].goal_in)+=a;
                        (tem[j].goal_agst)+=b;
                        (tem[i].tie)++;
                        (tem[j].tie)++;
                    }
                }
            }
        }
    }
}

int cmp_tm(const void *_a,const void *_b){
    char as[100],bs[100];
    int i;
    struct team *a = (struct team*)_a;
    struct team *b = (struct team*)_b;
    if(a->totpnt-b->totpnt) return -(a->totpnt-b->totpnt);
    else if(a->win-b->win) return -(a->win-b->win);
    else if((a->goal_in-a->goal_agst)-(b->goal_in-b->goal_agst)) return -((a->goal_in-a->goal_agst)-(b->goal_in-b->goal_agst));
    else if(a->goal_in - b->goal_in) return -(a->goal_in - b->goal_in);
    else if((b->win+b->tie+b->lose)-(a->win+a->tie+a->lose)) return -((b->win+b->tie+b->lose)-(a->win+a->tie+a->lose));
    else{
        for(i=0;i<strlen(a->name);i++) as[i]=tolower((a->name)[i]);
        for(i=0;i<strlen(b->name);i++) bs[i]=tolower((b->name)[i]);
        return strcmp(as,bs);
    }
}

void init(int nt){
    for(int i=0;i<nt;i++){
        tem[i].totpnt=0;
        tem[i].goal_in=0;
        tem[i].goal_agst=0;
        tem[i].win=0;
        tem[i].tie=0;
        tem[i].lose=0; 
    }
}

int main(){
    freopen(".\\in&outputs\\input36.txt","r",stdin);
    freopen(".\\in&outputs\\output36.txt","w",stdout);
    int N,bigi,nr,nt,i,j;
    char c[100],tnmt[200];
    scanf("%d",&N);getchar();
    for(bigi=0;bigi<N;bigi++){
        gets(tnmt);
        puts(tnmt);
        scanf("%d",&nt);getchar();
        init(nt);
        for(i=0;i<nt;i++){gets(tem[i].name);namelen[i]=strlen(tem[i].name);}
        scanf("%d",&nr);getchar();
        for(i=0;i<nr;i++){
            int f1,f2,f3,l;
            gets(c);
            l=strlen(c);
            for(j=0;j<l;j++){
                if(c[j]=='#') f1=j;
                else if(c[j]=='@'){
                    f2=j;
                    break;
                }
            }
            for(;j<l;j++){
                if(c[j]=='#'){
                    f3=j;
                    break;
                }
            }
            store(c,f1,f2,f3,l,nt);
        }
        qsort(tem,nt,sizeof(tem[0]),cmp_tm);
        for(i=0;i<nt;i++){
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,tem[i].name,tem[i].totpnt,tem[i].win+tem[i].tie+tem[i].lose,tem[i].win,tem[i].tie,tem[i].lose,tem[i].goal_in-tem[i].goal_agst,tem[i].goal_in,tem[i].goal_agst);
        }
        if(bigi<N-1) printf("\n");
    }
    return 0;
}
