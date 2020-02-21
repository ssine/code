#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct tpA{
    int x;
    int y;
    double k;
}Point;

int ptcmp(const void *_a,const void *_b){
    Point* a = ((Point*)_a);
    Point* b = ((Point*)_b);
    double d = a->k - b->k;
    if(d==0){
        if(a->x == b->x) return a->y - b->y;
        else return b->x - a->x;
    }
    int ans = d>0 ? -1 : 1;
    return ans;
}
inline double area(int x2,int y2,int x3,int y3){
    return fabs((x2*y3 - y2*x3)*1.0/2);
}
Point pt[105],leftmost;

int main(){
    freopen(".\\in&outputs\\input54.txt","r",stdin);
    freopen(".\\in&outputs\\output54.txt","w",stdout);
    int n,i,left;
    double cx,cy,mass,allm;
    while(scanf("%d",&n) && n>2){
        cx=0;cy=0;allm=0;
        scanf("%lld%lld",&pt[0].x,&pt[0].y);
        leftmost = pt[0]; left = 0;
        for(i=1;i<n;i++){
            scanf("%lld%lld",&pt[i].x,&pt[i].y);
            if(leftmost.x > pt[i].x){
                leftmost = pt[i];
                left = i;
            }else if(leftmost.x==pt[i].x && leftmost.y>pt[i].y){
                leftmost = pt[i];
                left = i;
            }
        }
        pt[left] = pt[n-1];
        for(i=0;i<n-1;i++){
            pt[i].x -= leftmost.x;
            pt[i].y -= leftmost.y;
            if(pt[i].x) pt[i].k = pt[i].y * 1.0 / pt[i].x;
            else pt[i].k = 9e307;
        }
        qsort(pt,n-1,sizeof(pt[0]),ptcmp);
        for(i=0;i<n-2;i++){
            mass = area(pt[i].x,pt[i].y,pt[i+1].x,pt[i+1].y);
            allm += mass;
            cx += (pt[i].x + pt[i+1].x)*1.0*mass/3;
            cy += (pt[i].y + pt[i+1].y)*1.0*mass/3;
        }
        printf("%.3lf %.3lf\n", cx/allm + leftmost.x, cy/allm + leftmost.y);
    }
}
