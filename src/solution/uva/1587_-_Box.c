#include<stdio.h>
#include<string.h>
int plts[6][2];

int main(){
    freopen(".\\in&outputs\\input63.txt","r",stdin);
    freopen(".\\in&outputs\\output63.txt","w",stdout);
    int i,j,flag,t1,t2,h;
    int ct[4];
    while(scanf("%d%d",&plts[0][0],&plts[0][1])==2){
        for(i=1; i<6; i++) scanf("%d%d",&plts[i][0],&plts[i][1]);
        memset(ct,0,sizeof(ct)); h=0;
        for(i=1; i<6; i++){
            for(j=0; j<2; j++){
                if(plts[i][j]==plts[0][0] && plts[i][1-j]==plts[0][1]){
                    t1 = plts[i][j]; t2 = plts[i][1-j];
                    plts[i][j] = plts[1][0]; plts[i][1-j] = plts[1][1];
                    plts[1][0] = t1; plts[1][1] = t2;
                    break;
                }
            }
            if(j<2) break;
        }
        if(i==7){ printf("IMPOSSIBLE\n"); continue;}
        for(i=2;i<6;i++){
            if(plts[i][0]==plts[0][0]&&plts[i][1]==plts[0][1]){
                ct[0]++;
            }else if(plts[i][0]==plts[0][1]&&plts[i][1]==plts[0][0]){
                ct[1]++;
            }else if(plts[i][0]==plts[i][1] && plts[i][0]==plts[0][0]){
                ct[2]++;
            }else if(plts[i][0]==plts[i][1] && plts[i][0]==plts[0][1]){
                ct[3]++;
            }
        }
        if((ct[0]==2 && ct[2]==2) || (ct[1]==2 && ct[3]==2)){printf("POSSIBLE\n");continue;}
        for(i=2;i<6;i++){
            if(plts[i][0]==plts[0][0]){
                if(!h) h = plts[i][1];
                if(h != plts[i][1]) break;
            }else if(plts[i][1]==plts[0][0]){
                if(!h) h = plts[i][0];
                if(h != plts[i][0]) break;
            }else if(plts[i][0]==plts[0][1]){
                if(!h) h = plts[i][1];
                if(h != plts[i][1]) break;
            }else if(plts[i][1]==plts[0][1]){
                if(!h) h = plts[i][0];
                if(h != plts[i][0]) break;
            }else{
                break;
            }
        }
        if(i<6) printf("IMPOSSIBLE\n");
        else printf("POSSIBLE\n");
    }
    return 0;
}
