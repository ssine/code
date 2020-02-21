#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 20;

struct Shoe{
    double ratio;
    short no;
    bool operator < (Shoe b) const {
        if(ratio != b.ratio) return ratio < b.ratio;
        else return no < b.no;
    }
};
Shoe lst[maxn];

int main() {
    freopen(".\\in&outputs\\in21","r",stdin);
    freopen(".\\in&outputs\\out21","w",stdout);
    int N; cin >> N;
    while(N--) {
        int n, t, f;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> t >> f;
            lst[i].ratio = t * 1.0 / f;
            lst[i].no = i + 1;
        }
        sort(lst, lst + n);
        for(int i = 0; i < n-1; i++) cout << lst[i].no << ' ';
        cout << lst[n-1].no << "\n";
        if(N > 0) cout << '\n';
    }
    return 0;
}
