#include<stdio.h>
const int maxn = 100005;
int ans[maxn]={0};

int main(){
    int T,n;
    for(int m=1; m<maxn; m++){
        int x = m, y = m;
        while(x>0) {y += x%10; x/=10; }
        if(ans[y] == 0 || m < ans[y]) ans[y] = m;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
