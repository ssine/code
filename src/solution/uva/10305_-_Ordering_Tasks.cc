#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 101;

int mat[MAXN][MAXN];
int indegree[MAXN];
int vis[MAXN];

void init() {
    memset(mat, 0, sizeof(mat));
    memset(indegree, 0, sizeof(indegree));
    memset(vis, 0, sizeof(vis));
}

int main() {
    int n, m;
    while(cin >> n >> m, n || m) {
        init();
        int p, a;
        for(int i = 0; i < m; i++) {
            cin >> p >> a;
            mat[p][a] = 1;
            indegree[a] ++;
        }

        while(true) {
            bool flag = false;
            for(int i = 1; i <= n; i++) {
                if(!vis[i] && !indegree[i]) {
                    vis[i] = 1;
                    for(int j = 1; j <= n; j++) {
                        if(mat[i][j])
                            indegree[j] --;
                    }
                    cout << i << ' ';
                    flag = true;
                }
            }
            if(!flag) break;
        }
        cout << endl;

    }
    return 0;
}
