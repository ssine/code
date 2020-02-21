#include<stdio.h>
#include<string.h>

char a[105][120],ans[150];
int len[120];

int main(){
    freopen("input24.txt","r",stdin);
    freopen("output24.txt","w",stdout);
    int i=0,j,max=0,n,sum,car=0,k;
    while(1){
        gets(a[i]);
        len[i] = strlen(a[i]);
        if(len[i]>max) max = len[i];
        if(a[i][0]=='0'&&len[i]==1) break;
        i++;
    }
    n = i;
    for(i=0;i<max;i++){
        sum=0;
        for(j=0;j<n;j++){
            if(len[j]-i-1<0) continue;
            sum += a[j][len[j]-i-1]-'0';
            k=1+1;
        }
        sum += car;
        ans[i] = sum%10+'0';
        car = sum/10;
    }
    if(car) printf("%d",car);
    for(i=0;i<max;i++) printf("%c",ans[max-i-1]);
    printf("\n");
    return 0;
}
