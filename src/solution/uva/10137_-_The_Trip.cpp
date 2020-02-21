#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    freopen(".\\in&outputs\\in26","r",stdin);
    freopen(".\\in&outputs\\out26","w",stdout);
    int n;
    while(cin >> n, n) {
        vector<int> lst(n);
        double cur; int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> cur;
            cur *= 100; cur = floor(cur + 0.5); //浮点精度
            sum += cur;
            lst[i] = floor(cur);
        }
        sort(lst.begin(), lst.end());
        double ave = sum * 1.0 / n / 100;

        int f = 0, e = n - 1, intave = floor(ave*100);
        if(ave - floor(ave*100)/100 < 0.00001) { //第一种情况
            while(lst[e] > intave) e--;
            int sume = 0;
            for(int i = n - 1; i > e; i--) sume += lst[i] - intave;
            printf("$%.2lf\n", sume * 1.0 / 100);
        } else {                                 //第二种情况
            while(lst[f] <= intave) f++;
            while(lst[e] > intave) e--;
            int sumf = 0, sume = 0;
            for(int i = 0; i < f; i++) sumf += intave - lst[i];
            for(int i = n - 1; i > e; i--) sume += lst[i] - intave - 1;
            printf("$%.2lf\n", max(sume, sumf) * 1.0 / 100);
        }
    }
    return 0;
}
