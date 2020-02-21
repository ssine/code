#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

const int maxt = 1000 + 10;

int main(){
    freopen(".\\in&outputs\\input64.txt","r",stdin);
    freopen(".\\in&outputs\\output64.txt","w",stdout);
    ios::sync_with_stdio(false);
    int t, kase = 0;
    while(cin >> t && t) {
        cout << "Scenario #" << ++kase << '\n';

        map<int, int> team;
        for(int i = 0; i < t; i++) {
            int n, x;
            cin >> n;
            while(n--) {cin >> x; team[x] = i; }
        }

        queue<int> q, q2[maxt];
        for(;;) {
            int x;
            char cmd[10];
            cin >> cmd;
            if(cmd[0] == 'S') break;
            else if(cmd[0] == 'D') {
                int t = q.front();
                cout << q2[t].front() << '\n'; q2[t].pop();
                if(q2[t].empty()) q.pop();
            }else if(cmd[0] == 'E') {
                cin >> x;
                int t = team[x];
                if(q2[t].empty()) q.push(t);
                q2[t].push(x);
            }
        }
        cout << '\n';
    }

    return 0;
}
