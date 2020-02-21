#include<stdio.h>
#include<string.h>
int l;
char s[105];
int small(int fir,int sec){
    int i;
    for(i=0;i<l;i++)
        if(s[(fir+i)%l]!=s[(sec+i)%l])
            return s[(fir+i)%l]>s[(sec+i)%l];
    return 0;
}

int main(){
    int T,i,min;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        l = strlen(s);
        min=0;
        for(i=1;i<l;i++)
            if(small(min,i)>0) min=i;
        for(i=0;i<l;i++)
            printf("%c",s[(min+i)%l]);
        printf("\n");
    }
    return 0;
}
