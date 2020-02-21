#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dish[45],contr[45],DNA[10];
char pr[5] = {' ','.','x','W'};

int main(){

    freopen("input7.txt","r",stdin);
    freopen("output7.txt","w",stdout);

    int ca,i,j,k,d=1;
    scanf("%d",&ca); getchar();
    for(i=0;i<ca;i++){ //总循环
        for(j=0;j<10;j++) scanf("%d",&DNA[j]);//读入DNA
        memset(dish,0,sizeof(dish));//初始化
        memset(contr,0,sizeof(contr));
        dish[20] = 1;
        d = 1;
        for(j=1;j<=40;j++) printf("%c",pr[dish[j]]);//打印Day1
        printf("\n");
        for(j = 1;j < 50; j++){ //49天
            for(k=1;k<=40;k++){ //处理密度
                if(d){
                    contr[k] = DNA[ dish[k-1]+dish[k]+dish[k+1] ];
                }else{
                    dish[k] = DNA[ contr[k-1]+contr[k]+contr[k+1] ];
                }
            }
            if(d){
                for(k=1;k<=40;k++) printf("%c",pr[contr[k]]);
                printf("\n");
            } else{
                for(k=1;k<=40;k++) printf("%c",pr[dish[k]]);
                printf("\n");
            }
            d = !d;
        }
        if(i<ca-1) printf("\n");
        getchar();
    }
    return 0;
}
