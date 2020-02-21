#include <iostream>
using namespace std;

const int maxn = 20000 + 10;

int main() {
    freopen(".\\in&outputs\\in42","r",stdin);
    freopen(".\\in&outputs\\out42","w",stdout);
    int n;
    cin >> n;
    for(int rt = 1; rt <= n; rt++) {
        int stop; cin >> stop;
        int l = 1, r = 1, s = 0, in;
        int  maxs = -1, maxl = 1, maxr = 1;
        for(int i = 1; i < stop; i++) {
            cin >> in;
            s += in;
            if(s > maxs || s == maxs && i-l > maxr-maxl) {
                maxs = s;
                r = i+1;
                maxl = l; maxr = r;
            } else if(s < 0) {
                s = 0;
                l = i+1;
            }
            // cout << maxs << ' ' << s << " | ";
        }
        if(maxs == -1) cout << "Route " << rt << " has no nice parts\n";
        else cout << "The nicest part of route " << rt << " is between stops " << maxl << " and " << maxr << "\n";
    }
}
