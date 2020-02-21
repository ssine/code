#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxT = 200 + 10;
const int maxN = 50 + 10;
const int INF = (int)2e9;

int has_train[maxT][maxN][2];
int t[maxN];
int dp[maxT][maxN];


int main() {
    freopen(".\\in&outputs\\in19","r",stdin);
    freopen(".\\in&outputs\\out19","w",stdout);
    int N, T, nl, nr, depart, kase = 0;
    while(cin >> N >> T) {
        memset(has_train, 0, sizeof(has_train));
        for(int i = 1; i < N; i++) cin >> t[i];

        cin >> nl;
        while(nl--) {
            cin >> depart;
            for(int i = 1; i < N; i++) {
                if(depart <= T) has_train[depart][i][1] = 1;
                depart += t[i];
            }
        }
        cin >> nr;
        while(nr--) {
            cin >> depart;
            for(int i = N-1; i >= 1; i--) {
                if(depart <= T) has_train[depart][i+1][0] = 1;
                depart += t[i];
            }
        }

        for(int i = 1; i < N; i++) dp[T][i] = INF;
        dp[T][N] = 0;

        for(int i = T - 1; i >= 0; i--)
            for(int j = 1; j <= N; j++) {
                dp[i][j] = dp[i+1][j] + 1;
                if(j < N && has_train[i][j][1] && i+t[j] <= T)
                    dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]);
                if(j > 1 && has_train[i][j][0] && i+t[j-1] <= T)
                    dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]);
            }

        for(int i = 0; i <= T; i++) {
            for(int j = 1; j <= N; j++) {
                if(dp[i][j] >= INF) cout << "INF ";
                else cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        
        cout << "Case Number " << ++kase << ": ";
        if(dp[0][1] >= INF) cout << "impossible\n";
        else cout << dp[0][1] << '\n';
    }
    return 0;
}
