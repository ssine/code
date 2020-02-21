#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char cbc1[7],cbc2[7];
int op1[5][5],op2[5][5],cb1[7],cb2[7],rgb1[5],rgb2[5];
int bor[7][7]=
{
{9,2,4,1,3,9},
{3,9,0,5,9,2},
{1,5,9,9,0,4},
{4,0,9,9,5,1},
{2,9,5,0,9,3},
{9,3,1,4,2,9},
};

int doucmp(){
    int i,ct=0;
    for(i=1;i<=3;i++){
        if(memcmp(op1[i],op2[i],sizeof(op1[i]))==0) ct++;
    }
    if(ct==3) return 1;
    else return 0;
}

int colorn(){
    memset(rgb1,0,sizeof(rgb1));
    memset(rgb2,0,sizeof(rgb2));
    int i;
    for(i=0;i<6;i++){
        rgb1[cb1[i]]++;
        rgb2[cb2[i]]++;
    }
    return memcmp(rgb1,rgb2,sizeof(rgb1));
}

int opc(){
    memset(op1,0,sizeof(op1));
    memset(op2,0,sizeof(op2));
    int i;
    for(i=0;i<3;i++){
        op1[cb1[i]][cb1[5-i]] = 1;
        op1[cb1[5-i]][cb1[i]] = 1;
        op2[cb2[i]][cb2[5-i]] = 1;
        op2[cb2[5-i]][cb2[i]] = 1;
    }
    if(doucmp()) return 1;
    else return 0;
}

int border(){
    int i,j,k;
    for(i=0;i<6;i++){
        if(cb2[i]==cb1[0]){
            for(j=0;j<6;j++){
                if(j==i||j==(5-i)) continue;
                if(cb2[j]==cb1[1]){
                    if(cb2[bor[i][j]]==cb1[2])
                        if(cb2[bor[j][i]]==cb1[3])
                            if(cb2[5-j]==cb1[4]) return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    freopen("input23.txt","r",stdin);
    freopen("output23.txt","w",stdout);
    int i;
    while(fgets(cbc1,7,stdin)){
        fgets(cbc2,7,stdin);
        getchar();
        for(i=0;i<6;i++){//数字化
            switch(cbc1[i]){
                case 'r' : cb1[i]=1;break;
                case 'g' : cb1[i]=2;break;
                case 'b' : cb1[i]=3;break;
            }
            switch(cbc2[i]){
                case 'r' : cb2[i]=1;break;
                case 'g' : cb2[i]=2;break;
                case 'b' : cb2[i]=3;break;
            }
        }
        if(colorn()==0){//两魔方颜色相同
            if(opc()){//对侧颜色相同
                if(border()){//三块接邻色相同
                    printf("TRUE\n");
                }else{
                    printf("FALSE\n");
                }
            }else{
                printf("FALSE\n");
            }
        }else{
            printf("FALSE\n");
        }
    }
    return 0;
}
