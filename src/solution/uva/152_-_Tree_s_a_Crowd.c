#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include<time.h>

//clock_t clock();

int pst[5020][3],ct[12]={0},dis[5010][5010];

double d(int i,int j){
    double x1=pst[i][0],y1=pst[i][1],z1=pst[i][2];
    double x2=pst[j][0],y2=pst[j][1],z2=pst[j][2];
    double dx=x1-x2,dy=y1-y2,dz=z1-z2;
    return sqrt(dx*dx+dy*dy+dz*dz);
}

int main(){
    freopen(".\\in&outputs\\input29.txt","r",stdin);
    freopen(".\\in&outputs\\output29.txt","w",stdout);
    int i=-1,j,n,_d,min;
    while(i++,scanf("%d%d%d",&pst[i][0],&pst[i][1],&pst[i][2]),pst[i][0]+pst[i][1]+pst[i][2]!=0);
    n=i;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            _d=(int)floor(d(i,j));
            dis[i][j] = _d;
            dis[j][i] = _d;
        }
    }
    for(i=0;i<n;i++){
        min=1000;
        for(j=0;j<n;j++){
            if(j==i) continue;
            if(dis[i][j]<min) min = dis[i][j];
        }
        if(min<10) ct[min]++;
    }
    for(i=0;i<10;i++) printf("%4d",ct[i]);
    //printf("\n%d\n",clock());
    printf("\n");
    return 0;
}
