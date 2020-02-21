#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char st[200];

void check(char s0[23],char s1[23],int tot){
    int i = 0,pa = 0,mi = 0,ct=0;
    for(i=0;i<=tot/2;i++){
        if(s0[i]==s0[tot-i]) ct++;
    }
    if(ct==tot/2+1) pa=1;
    ct=0;
    for(i=0;i<=tot;i++){
        if(s0[i]==s1[tot-i]) ct++;
    }
    if(ct==tot+1) mi=1;

    if(pa&&mi) {for(i=0;i<=tot;i++)printf("%c",s0[i]); printf(" -- is a mirrored palindrome.\n\n");}
    if(pa&&!mi) {for(i=0;i<=tot;i++)printf("%c",s0[i]); printf(" -- is a regular palindrome.\n\n");}
    if(!pa&&mi) {for(i=0;i<=tot;i++)printf("%c",s0[i]); printf(" -- is a mirrored string.\n\n");}
    if(!pa&&!mi) {for(i=0;i<=tot;i++)printf("%c",s0[i]); printf(" -- is not a palindrome.\n\n");}
}

int main(){

st['A']='A';st['B']=' ';st['C']=' ';st['D']=' ';st['E']='3';st['F']=' ';st['G']=' ';
st['H']='H';st['I']='I';st['J']='L';st['K']=' ';st['L']='J';st['M']='M';st['N']=' ';
st['O']='O';st['P']=' ';st['Q']=' ';st['R']=' ';st['S']='2';st['T']='T';st['U']='U';
st['V']='V';st['W']='W';st['X']='X';st['Y']='Y';st['Z']='5';st['1']='1';st['2']='S';
st['3']='E';st['4']=' ';st['5']='Z';st['6']=' ';st['7']=' ';st['8']='8';st['9']=' ';
st['0']='O';

    freopen("input13.txt","r",stdin);
    freopen("output13.txt","w",stdout);
    char s0[23],s1[23],c='A';
    int i=0;
    while(c!=EOF){
        c=getchar();
        if(c=='\n'){
            if(c==EOF&&i==0)break;
            check(s0,s1,i-1);
            i=0;
            continue;
        }
        s0[i] = c;
        s1[i] = st[c];
        i++;
    }
    return 0;
}
