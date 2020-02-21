#include <iostream>
#include <cstring>
using namespace std;
const int maxT = 200 + 10;
const int maxN = 50 + 10;
const int INF = (int)2e9;

int has_train[maxT][maxN][2];
int t[maxN];
int dpstore[maxT][maxN];
int T;

int dp(int curtime, int station) {
    if(dpstore[curtime][station] >= 0) return dpstore[curtime][station];
    int ans = INF;
    ans = min(ans, dp(curtime + 1, station) + 1);
    if(has_train[curtime][station][1] && curtime + t[station-1] <= T)
        ans = min(ans, dp(curtime + t[station-1], station - 1));
    if(has_train[curtime][station][0] && curtime + t[station] <= T)
        ans = min(ans, dp(curtime + t[station], station + 1));
    return dpstore[curtime][station] = ans;
}

int main() {
    freopen(".\\in&outputs\\in19","r",stdin);
    freopen(".\\in&outputs\\out19","w",stdout);
    int N, nl, nr, depart, kase = 0;
    while(cin >> N >> T) {
        memset(has_train, 0, sizeof(has_train));
        memset(dpstore, -1, sizeof(dpstore));
        for(int i = 1; i < N; i++) cin >> t[i];

        cin >> nl;
        while(nl--) {
            cin >> depart;
            for(int i = 1; i < N; i++) {
                if(depart <= T) has_train[depart][i][0] = 1;
                depart += t[i];
            }
        }
        cin >> nr;
        while(nr--) {
            cin >> depart;
            for(int i = N-1; i >= 1; i--) {
                if(depart <= T) has_train[depart][i+1][1] = 1;
                depart += t[i];
            }
        }

        for(int i = 1; i < N; i++) dpstore[T][i] = INF;
        dpstore[T][N] = 0;

        int ans = dp(0, 1);

        for(int i = 0; i <= T; i++) {
            for(int j = 1; j <= N; j++) {
                if(dpstore[i][j] >= INF) cout << "INF ";
                else cout << dpstore[i][j] << ' ';
            }
            cout << '\n';
        }
        
        cout << "Case Number " << ++kase << ": ";
        if(ans >= INF) cout << "impossible\n";
        else cout << ans << '\n';
    }
    return 0;
}
