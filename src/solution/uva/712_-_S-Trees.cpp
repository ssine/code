#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 8;

int N;
int positionToIndex[maxn];
int ter[1 << maxn];
char VVA[maxn+2];

int calc() {
    int l = 0, r = 1 << N;
    for(int i = 1; i <= N; i++) {
        if(VVA[positionToIndex[i]] == '0') r = (l + r) / 2;
        else l = (l + r) / 2;
    }
    return ter[l];
}

int main() {
    freopen(".\\in&outputs\\in37", "r", stdin);
    freopen(".\\in&outputs\\out37", "w", stdout);
    int cnt = 1;
    while(cin >> N, N) {
        string s;
        for(int i = 1; i <= N; i++) {
            cin >> s;
            positionToIndex[i] = s[1] - '0';
        }
        cin >> s;
        for(int i = 0; i < s.length(); i++) {
            ter[i] = s[i] - '0';
        }

        cout << "S-Tree #" << cnt++ << ":\n";
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> VVA+1;
            cout << calc();
        }
        cout << endl << endl;
    }
    return 0;
}
