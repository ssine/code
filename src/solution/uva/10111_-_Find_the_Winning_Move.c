#include<stdio.h>

char chessboard[4][4];
int xwin;
int xmove(int,int); //forced win - 1 else 0
int omove(int,int); //have a x forced win - 1 else 0
int judge(char);

int main(){
    freopen(".\\in&outputs\\input52.txt","r",stdin);
    freopen(".\\in&outputs\\output52.txt","w",stdout);
    int i,j,bn;
    while(getchar()=='?'){
        xwin=0;bn=0;
        getchar();
        for(i=0;i<4;i++) gets(chessboard[i]);
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(chessboard[i][j]!='.'){
                    bn++;
                }
            }
        }
        if(bn<=4) {printf("#####\n");continue;}
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(chessboard[i][j]=='.'){
                    if(xmove(i,j)) {xwin=1;break;} //is i,j a forced win? 
                }
            }
            if(xwin) break;
        }
        if(xwin) printf("(%d,%d)\n",i,j);
        else printf("#####\n");
    }
    return 0;
}

int xmove(int x,int y){
    int i,j;
    chessboard[x][y] = 'x';
    if(judge('x')){                 //immediate solution
        chessboard[x][y] = '.';
        return 1;
    }
    for(i=0;i<4;i++){               //all next omove has a forced win
        for(j=0;j<4;j++){
            if(chessboard[i][j]=='.')
            if(!omove(i,j)){
                chessboard[x][y] = '.';
                return 0;
            }
        }
    }
    chessboard[x][y] = '.';
    return 1;
}

int omove(int x,int y){
    int i,j;
    chessboard[x][y] = 'o';
    if(judge('o')){                 //o wins, no way
        chessboard[x][y] = '.';
        return 0;
    }
    for(i=0;i<4;i++){               //for all blank chessboard, have a forced win
        for(j=0;j<4;j++){
            if(chessboard[i][j]=='.')
            if(xmove(i,j)){
                chessboard[x][y] = '.';
                return 1;
            }
        }
    }
    chessboard[x][y] = '.';
    return 0;
}

int judge(char c){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(chessboard[i][j]!=c) break;
        }
        if(j==4) return 1;
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(chessboard[j][i]!=c) break;
        }
        if(j==4) return 1;
    }
    if(chessboard[0][0]==c&&chessboard[1][1]==c&&chessboard[2][2]==c&&chessboard[3][3]==c) return 1;
    if(chessboard[0][3]==c&&chessboard[1][2]==c&&chessboard[2][1]==c&&chessboard[3][0]==c) return 1;
    return 0;
}
