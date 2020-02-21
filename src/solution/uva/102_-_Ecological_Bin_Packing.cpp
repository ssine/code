#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct bin{
    string name;
    int num;
};
bool bscmp(bin a, bin b){
    int d = a.num - b.num;
    if(d) return a.num<b.num;
    else return a.name<b.name;
}

int main(){
    freopen(".\\in&outputs\\input51.txt","r",stdin);
    freopen(".\\in&outputs\\output51.txt","w",stdout);
    int a[5],b[5],c[5],i,sum;
    bin bs[10];
    while(cin>>a[0]){
        for(i=1;i<3;i++) cin>>a[i];
        for(i=0;i<3;i++) cin>>b[i];
        for(i=0;i<3;i++) cin>>c[i];
        sum = a[0]+a[1]+a[2]+b[0]+b[1]+b[2]+c[0]+c[1]+c[2];
        bs[0].name = "BGC";
        bs[1].name = "BCG";
        bs[2].name = "GBC";
        bs[3].name = "CBG";
        bs[4].name = "GCB";
        bs[5].name = "CGB";
        bs[0].num = sum-a[0]-b[1]-c[2];
        bs[1].num = sum-a[0]-b[2]-c[1];
        bs[2].num = sum-a[1]-b[0]-c[2];
        bs[3].num = sum-a[2]-b[0]-c[1];
        bs[4].num = sum-a[1]-b[2]-c[0];
        bs[5].num = sum-a[2]-b[1]-c[0];
        partial_sort(bs,bs+1,bs+6,bscmp);
        cout << bs[0].name << ' ' << bs[0].num << endl ;
    }
    return 0;
}
