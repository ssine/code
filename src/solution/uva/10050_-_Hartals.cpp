#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main() {
    freopen(".\\in&outputs\\in33", "r", stdin);
    freopen(".\\in&outputs\\out33", "w", stdout);
    int T; cin >> T;
    while(T--) {
        int N, P; cin >> N >> P;
        int cur;
        set<int> D;
        for(int i = 0; i < P; i++) {
            cin >> cur;
            int d = cur;
            while(d <= N) {
                if(d % 7 != 6 && d % 7 != 0)
                    D.insert(d);
                d += cur;
            }
        }
        cout << D.size() << endl;
    }
    return 0;
}
