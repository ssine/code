#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 20000 + 20;

int head[maxn], knight[maxn];

int main() {
    freopen(".\\in&outputs\\in22","r",stdin);
    freopen(".\\in&outputs\\out22","w",stdout);
    int m, n;
    while(cin >> m >> n, m&&n) {
        for(int i = 0; i < m; i++) scanf("%d", &head[i]);
        for(int i = 0; i < n; i++) scanf("%d", &knight[i]);
        if(m > n) {
            cout << "Loowater is doomed!\n";
            continue;
        }

        sort(head, head + m);
        sort(knight, knight + n);

        bool ok = true;
        int hp = 0, kp = 0, coin = 0;
        for(; hp < m; hp++) {
            while(knight[kp] < head[hp] && kp < n) kp++;
            if(n - kp < m - hp) {ok = false; break;}
            coin += knight[kp++];
        }

        if(ok) cout << coin << '\n';
        else cout << "Loowater is doomed!\n";
    }
    return 0;
}
