#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100 + 1;

int sumar[maxn][maxn] = {0}, ar[maxn][maxn];

int main() {
    freopen(".\\in&outputs\\in43", "r", stdin);
    freopen(".\\in&outputs\\out43", "w", stdout);
    int n;
    while(cin >> n) {

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                cin >> ar[i][j];

        for(int i = 1; i <= n; i++) {
            int subsum = 0;
            for(int j = 1; j <= n; j++) {
                subsum += ar[i][j];
                sumar[i][j] = sumar[i-1][j] + subsum;
            }
        }

        int maxval = -128000000, cursum;
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                for(int x = 1; x <= n; x++) {
                    for(int y = x; y <= n; y++) {
                        cursum = sumar[j][y] - sumar[i-1][y] - sumar[j][x-1] + sumar[i-1][x-1];
                        // cout << cursum << ' ';
                        maxval = max(cursum, maxval);
                    }
                }
            }
        }

        cout << maxval << '\n';
    }
    return 0;
}
