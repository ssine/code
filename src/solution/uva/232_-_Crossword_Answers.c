#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
char map[12][12];
int r,c,ar,ac,ansr[70][2][2],ansc[70][2][2],N=1;

int main(){
    freopen(".\\in&outputs\\input59.txt","r",stdin);
    freopen(".\\in&outputs\\output59.txt","w",stdout);
    int i,j,k,cur;
    int digmap[12][12];
    scanf("%d",&r);
    while(r){
        scanf("%d",&c); getchar();
        ar=0; ac=0; cur=1;
        memset(digmap,0,sizeof(digmap));
        memset(map,'*',sizeof(map));
        for(i=0;i<r;i++) gets(map[i]);
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if((i==0||j==0||map[i-1][j]=='*'||map[i][j-1]=='*')&&isalpha(map[i][j])){
                    digmap[i][j] = cur++;
                    if(!isalpha(map[i-1][j]) || i==0){
                        k = i;
                        while(k<=r && isalpha(map[k][j])) k++;
                        ansc[ac][0][0] = i;
                        ansc[ac][0][1] = j;
                        ansc[ac][1][0] = k-1;
                        ansc[ac++][1][1] = j;
                    }
                    if(!isalpha(map[i][j-1]) || j==0){
                        k = j;
                        while(k<=c && isalpha(map[i][k])) k++;
                        ansr[ar][0][0] = i;
                        ansr[ar][0][1] = j;
                        ansr[ar][1][0] = i;
                        ansr[ar++][1][1] = k-1;
                    }
                }
            }
        }
        printf("puzzle #%d:\n",N++);
        printf("Across\n");
        for(i=0;i<ar;i++){
            printf("%3d.",digmap[ansr[i][0][0]][ansr[i][0][1]]);
            for(j=ansr[i][0][1];j<=ansr[i][1][1];j++){
                printf("%c",map[ansr[i][0][0]][j]);
            }
            printf("\n");
        }
        printf("Down\n");
        for(i=0;i<ac;i++){
            printf("%3d.",digmap[ansc[i][0][0]][ansc[i][0][1]]);
            for(j=ansc[i][0][0];j<=ansc[i][1][0];j++){
                printf("%c",map[j][ansc[i][0][1]]);
            }
            printf("\n");
        }
        scanf("%d",&r);
        if(r) printf("\n");
    }
    return 0;
}
