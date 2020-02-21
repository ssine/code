#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char DNA[52][1005],ans[1005];
int prj[256],hash[4];
const char* rprj = "ACGT";
void init(){
    prj['A'] = 0;
    prj['C'] = 1;
    prj['G'] = 2;
    prj['T'] = 3;
}

int main(){
    freopen(".\\in&outputs\\input60.txt","r",stdin);
    freopen(".\\in&outputs\\output60.txt","w",stdout);
    int N,m,n,i,j,max,hmdist;
    init();
    scanf("%d",&N);
    while(N--){
        /*initialize*/
        scanf("%d%d",&m,&n); getchar();
        for(i=0;i<m;i++) gets(DNA[i]);
        memset(ans,0,sizeof(ans));
        hmdist = 0;

        /*calculate*/
        for(j=0;j<n;j++){
            memset(hash,0,sizeof(hash));
            for(i=0;i<m;i++){
                hash[prj[DNA[i][j]]]++;
            }
            max = -1;
            for(i=0;i<4;i++) if(hash[i] > max) max = hash[i];
            for(i=0;i<4;i++){
                if(hash[i]==max){
                    ans[j] = rprj[i];
                    hmdist += (m - max);
                    break;
                }
            }
        }
        ans[j] = 0;

        /*print*/
        printf("%s\n%d\n",ans,hmdist);
    }
    return 0;
}
