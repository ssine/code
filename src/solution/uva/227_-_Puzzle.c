#include<stdio.h>
#include<stdlib.h>
char map[5][6];
int N=0,flag;
void swap(int,int,int,int);
void printmap();

int main(){
    freopen(".\\in&outputs\\input58.txt","r",stdin);
    freopen(".\\in&outputs\\output58.txt","w",stdout);
    int i,j,x,y;
    char c;
    while(1){
        i=0;
        gets(map[i]);
        if(map[0][0]=='Z') break;
        for(i=1;i<5;i++) gets(map[i]);
        if(N>0) printf("\n");
        N++; flag=0;
        for(i=0;i<5;i++)
            for(j=0;j<5;j++)
                if(map[i][j]==' '||map[i][j]=='\0'){
                    x = j;
                    y = i;
                }
        while((c=getchar())!='0'){
            if(flag) continue;
            switch(c){
                case 'A':
                    swap(x,y,x,y-1); y--; break;
                case 'B':
                    swap(x,y,x,y+1); y++; break;
                case 'L':
                    swap(x,y,x-1,y); x--; break;
                case 'R':
                    swap(x,y,x+1,y); x++; break;
                case '\n':
                    continue;
                default:
                    flag = 1;
            }
        }
        getchar();
        printmap();
    }
    return 0;
}

void swap(int x1,int y1,int x2,int y2){
    if(x1>4||x1<0||x2>4||x2<0||y1>4||y1<0||y2>4||y2<0){
        flag=1;
        return;
    }
    char c = map[y1][x1];
    map[y1][x1] = map[y2][x2];
    map[y2][x2] = c;
    return;
}

void printmap(){
    int i;
    if(flag) printf("Puzzle #%d:\nThis puzzle has no final configuration.\n",N);
    else{
        printf("Puzzle #%d:\n",N);
        for(i=0;i<5;i++){
            printf("%c %c %c %c %c\n",map[i][0],map[i][1],map[i][2],map[i][3],map[i][4]);
        }
    }
    return;
}
