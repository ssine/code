#include<stdio.h>
#include<math.h>

int main(){
    freopen(".\\in&outputs\\input48.txt","r",stdin);
    freopen(".\\in&outputs\\output48.txt","w",stdout);
    long long int a,b,s,m,n;
    double r,rt,v,cpi=180/(4*atan(1.0));
    while(scanf("%lld%lld%lld%lld%lld",&a,&b,&s,&m,&n),a||b||s||m||n){
        r = fabs(atan(n*b*1.0/(m*a)))*cpi;
        rt = sqrt((n*b)*(n*b)+(m*a)*(m*a));
        v = rt/s;
        printf("%.2lf %.2lf\n",r,v);
    }
    return 0;
}
