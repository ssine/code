#include<stdio.h>
#include<stdlib.h>

int main(){
    int brk[110],n,i,sum,ave,ct,ca=1;
    while(scanf("%d",&n),n!=0){
        sum=0;ct=0;
        for(i=0;i<n;i++){
            scanf("%d",&brk[i]);
            sum+=brk[i];
        }
        ave = sum/n;
        for(i=0;i<n;i++)
            if(brk[i]>ave) ct+=brk[i]-ave;
        printf("Set #%d\n",ca++);
        printf("The minimum number of moves is %d.\n\n",ct);
    }
    //system("pause");
    return 0;
}
