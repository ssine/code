#include<stdio.h>

int main(){
    int N,i,a,b,p;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d%d",&a,&b);
        p = ((a-2)%3?(a-2)/3+1:(a-2)/3)*((b-2)%3?(b-2)/3+1:(b-2)/3);
        printf("%d\n",p);
    }
    return 0;
}
