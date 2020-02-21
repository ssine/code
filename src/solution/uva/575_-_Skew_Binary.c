#include<stdio.h>
#include<string.h>
int pow2(int);

int main(){
    char s[100];
    int b[100],i,sum,l;
    while(gets(s),!(s[0]=='0'&&strlen(s)==1)){
        l = strlen(s);
        sum = 0;
        for(i=0;i<l;i++){
            sum += (s[l-i-1]-'0')*(pow2(i+1)-1);
        }
        printf("%d\n",sum);
    }
}

int pow2(int n){
    int i,sum=1;
    for(i=0;i<n;i++)
        sum*=2;
    return sum;
}
