#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

const int maxn = 1000000;

int mp[maxn+10] = {0};

int calc(long long n){
    if(mp[n]) return mp[n];
    int ct = 1, n_ = n;
    while(n >> 1) {
        if(n < maxn && mp[n]) {
            ct += mp[n] - 1;
            break;
        }
        if(n & 1) {
            n += (n>>1) + 1;
            ct += 2;
        }else{
            n >>= 1;
            ct++;
        } 
    }
    return mp[n_] = ct;
}


int main(){
    freopen(".\\in&outputs\\input49.txt","r",stdin);
    freopen(".\\in&outputs\\output49.txt","w",stdout);
    int a = 1, b = maxn, curm = calc(a), curmp = a;
    for(int i = a + 1; i <= b ; i++) {
        int c = calc(i);
        if(c > curm) {
            curm = c;
            curmp = i;
        }
    }

    printf("%d\n%d", curmp, curm);
    return 0;
}

