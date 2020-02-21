#include <iostream>
#include <cstdio>
using namespace std;

const int N = 21;

double ratio[N][N], dp[N][N][N];
int path[N][N][N];
int n;

void output(int i, int j, int r) {
    if(r == 1) {
        cout << i << ' ' << j;
        return;
    }
    output(i, path[r][i][j], r-1);
    cout << ' ' << j;
    return;
}

int main() {
    freopen(".\\in&outputs\\in39", "r", stdin);
    freopen(".\\in&outputs\\out39", "w", stdout);
    while(cin >> n) {
        // process input & initialize
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < i; j++) cin >> ratio[i][j];
            ratio[i][i] = 1;
            for(int j = i+1; j <= n; j++) cin >> ratio[i][j];
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[1][i][j] = ratio[i][j];

        // dp
        for(int r = 2; r <= n+1; r++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    double maxn = -1; int maxp = -1;
                    for(int k = 1; k <= n; k++) {
                        if(dp[r-1][i][k]*ratio[k][j] > maxn) {
                            maxp = k;
                            maxn = dp[r-1][i][k]*ratio[k][j];
                        }
                    }
                    dp[r][i][j] = maxn;
                    path[r][i][j] = maxp;

                    if(i == j && maxn > 1.01) {
                        // solution found
                        output(i, j, r);
                        cout << '\n';
                        goto found;
                    }
                }
            }
        }

        cout << "no arbitrage sequence exists\n";

        found:
            continue;
    }
    return 0;
}
