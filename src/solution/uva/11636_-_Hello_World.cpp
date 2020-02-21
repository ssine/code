#include <iostream>
#include <cstdio>
using namespace std;

int num[15];

int main() {
    for(int i = 0; i < 15; i++) num[i] = 1 << i;
    int n, kase = 1;;
    while(scanf("%d", &n), n >= 0) {
        int i = 0;
        while(num[i] < n) i++;
        printf("Case %d: %d\n", kase++, i);
    }
    return 0;
}
