#include<stdio.h>
#include<ctype.h>
#include<string.h>
float m[4] = {12.01,1.008,16,14.01};

int main(){
    int T,i,l,e,n;
    double mass;
    char s[100];
    scanf("%d",&T); getchar();
    while(T--){
        mass=0;
        gets(s);
        l = strlen(s);
        for(i=0;i<l;i++){
            switch(s[i]){
                case'C': e=0;break;
                case'H': e=1;break;
                case'O': e=2;break;
                case'N': e=3;break;
            }
            if(isalpha(s[i+1])||s[i+1]=='\0') n=1;
            else{
                sscanf(&s[i+1],"%d",&n);
                while(!isalpha(s[i+1])) i++;
            }
            mass += n*m[e];
        }
        printf("%.3f\n",mass);
    }
    return 0;
}
