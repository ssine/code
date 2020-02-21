#include<stdio.h>

int main(){
    int i,n,k,ad,num[20000];
    num[0]=0;
    while(scanf("%d%d%d",&n,&num[1],&k)==3){
        i=2;ad=0;
        do{
            if(i!=2) ad = (ad+num[i-2]*k)/n;
            num[i] = (ad+num[i-1]*k)%n;
            i++;
        }while(num[i-2]*k+ad != num[1]);
        printf("%d\n",i-2);
    }
    return 0;
}
