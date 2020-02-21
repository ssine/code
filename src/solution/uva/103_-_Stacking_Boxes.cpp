#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 30 + 5;

struct BOX{
    vector<int> len;
    bool operator < (const BOX& b) const {
        for(int i = 0; i < len.size(); i++) {
            if(len[i] >= b.len[i]) return false;
        }
        return true;
    }
};

int dp(int);
void print(int, int);

int include[maxn][maxn];  //in[i][j] == 1  =>  i > j
int map[maxn];
int n, dim;
BOX box[maxn];

int main() {
    freopen(".\\in&outputs\\in12","r",stdin);
    freopen(".\\in&outputs\\out12","w",stdout);
    while(cin >> n >> dim) {
        for(int i = 0; i < n; i ++) {
            int cur;
            box[i].len.clear();
            for(int j = 0; j < dim; j++) {
                cin >> cur;
                box[i].len.push_back(cur);
            }
            sort(box[i].len.begin(), box[i].len.end());
        }

        memset(include, -1, sizeof(include));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n ; j++)
                if(box[j] < box[i])
                    include[i][j] = 1;

        memset(map, -1, sizeof(map));
        int maxb = -1, num;
        for(int i = 0; i < n; i++) {
            int t = dp(i);
            if(maxb < t) {
                maxb = t;
                num = i;
            }
        }

        cout << maxb + 1 << '\n';
        print(num, maxb);
        cout << '\n';
    }
    return 0;
}

int dp(int cur) {
    if(map[cur] != -1) return map[cur];
    map[cur] = -2;
    int maxlen = 0;
    for(int i = 0; i < n; i++) {
        if(i == cur) continue;
        if(map[i] == -2) continue;
        if(include[cur][i] == 1) {
            maxlen = max(maxlen, dp(i) + 1);
        }
    }
    return map[cur] = maxlen;
}

void print(int num, int maxlen) {
    int mxn, mxl;
    stack<int> st;
    st.push(num + 1);
    for(int i = 0; i < maxlen; i++) {
        mxn = mxl = -1;
        for(int j = 0; j < n; j++) {
            if(j == num) continue;
            if(include[num][j] == 1) {
                if(map[j] > mxl) {
                    mxl = map[j];
                    mxn = j;
                }
            }
        }
        st.push(mxn + 1);
        num = mxn;
    }

    cout << st.top();
    st.pop();
    while(!st.empty()) {
        cout << ' ' << st.top();
        st.pop();
    }
}
