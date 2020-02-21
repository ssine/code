#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct building {
    int id;
    double x, y, w, h;
    bool visible;
    bool operator < (const building& b) const {
        return x < b.x || (x == b.x && y < b.y);
    }
};
vector<building> bd;

bool cover(int n, double mx) {
    return bd[n].x <= mx && bd[n].x+bd[n].w >= mx;
}

bool visible(int n, double mx) {
    if(!cover(n, mx)) return false;
    for(int i = 0; i < n; i++) {
        if(bd[i].y < bd[n].y && bd[i].h >= bd[n].h && cover(i, mx)) return false;
    }
    return true;
}

int main() {
    freopen(".\\in&outputs\\in2","r",stdin);
    freopen(".\\in&outputs\\out2","w",stdout);
    int n, N = 0;
    while(cin >> n && n) {
        double x;
        vector<double> x_axis;
        bd.clear(); bd.resize(n);
        for(int i = 0; i < n; i++) {
            cin >> bd[i].x >> bd[i].y >> bd[i].w >> x >> bd[i].h;
            x_axis.push_back(bd[i].x);
            x_axis.push_back(bd[i].x + bd[i].w);
            bd[i].id = i + 1;
        }
        sort(bd.begin(), bd.end());

        sort(x_axis.begin(), x_axis.end());
        vector<double>::iterator it = unique(x_axis.begin(), x_axis.end());
        x_axis.erase(it, x_axis.end());

        if(N++) cout << '\n';
        cout << "For map #" << N << ", the visible buildings are numbered as follows:\n";
        cout << bd[0].id;
        for(int i = 1; i < n; i++) {
            bool vis = false;
            for(int j = 0; j < x_axis.size(); j++) {
                if(visible(i, (x_axis[j]+x_axis[j+1])/2)) {
                    vis = true;
                    break;
                }
            }
            if(vis) cout << ' ' << bd[i].id;
        }
        cout << '\n';
    }
    return 0;
}
