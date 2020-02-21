#include<stdio.h>
#include<stdlib.h>
int main(){
    int num,i,a,f,j,k,l;
    //freopen("input4.txt","r",stdin);
    //freopen("output4.txt","w",stdout);
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("\n%d%d",&a,&f);
        for(j = 0;j<f;j++){
            for(k=1;k<=a;k++){
                for(l=1;l<=k;l++) printf("%d",k);
                printf("\n");
            }
            for(k=a-1;k>0;k--){
            for(l=1;l<=k;l++) printf("%d",k);
            printf("\n");
            }
            if((j==f-1)&&(i==num-1)) break;
            printf("\n");
        }
    }
    system("pause");
    return 0;

}
