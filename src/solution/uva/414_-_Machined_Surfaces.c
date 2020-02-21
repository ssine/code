#include<stdio.h>
#include<stdlib.h>

char m[14][26];

int main(){
    int n,i,min = 26,j,c,all=0;
    while(scanf("%d",&n)){
        getchar();
        //printf("n: %d\n",n);
        if(n == 0) break;
        for(i=0;i<n;i++){
            gets(m[i]);
            c=0;
            for(j=0;j<25;j++) if(m[i][j] != 'X') c++;
            all += c;
            //printf("all: %d\n",all);
            if(c<min) min = c;
        }
        printf("%d\n",all - min*n);
        min = 26;
        all = 0;
    }
    system("pause");
}
