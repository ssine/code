#include<stdio.h>

int main(){
    int n;
    double p;
    while(scanf("%d",&n),n>=0){
        if(n==1){printf("0%%\n");continue;}
        p = n/4.0*100;
        printf("%.0lf%%\n",p);
    }
    return 0;
}
