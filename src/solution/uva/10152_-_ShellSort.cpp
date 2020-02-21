#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int main() {
    freopen(".\\in&outputs\\in29", "r", stdin);
    freopen(".\\in&outputs\\out29", "w", stdout);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        getchar();
        vector<string> r(n);
        vector<string> g(n);
        for(int i = n - 1; i >= 0; i--)
            getline(cin, r[i]);
        for(int i = n - 1; i >= 0; i--)
            getline(cin, g[i]);
        int rp = 0, gp = 0;
        while(rp < n) {
            if(g[gp] == r[rp]) gp++;
            rp++;
        }
        for(; gp < n; gp++)
            cout << g[gp] << '\n';
        cout << '\n';
    }
    return 0;
}
