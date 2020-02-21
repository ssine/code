#include <iostream>
#include <stack>
using namespace std;
const int maxn = 1000 + 10;

int goal[maxn];

int main() {
    freopen(".\\in&outputs\\in15","r",stdin);
    freopen(".\\in&outputs\\out15","w",stdout);
    int N;
    while(cin >> N, N) {
        while(cin >> goal[0], goal[0]) {
            stack<int> s;
            int cur = 0;
            bool ok = true;
            for(int i = 1; i < N; i++)
                cin >> goal[i];
            for(int cur = 0, id = 0; cur < N; cur++) {
                if(id < N) id++;
                if(goal[cur] == id) {
                    continue;
                } else if(goal[cur] > id) {
                    for(int j = id; j < goal[cur]; j++) s.push(j);
                    id = goal[cur];
                } else if(s.empty()) {
                    ok = false;
                    break;
                } else if(goal[cur] == s.top()) {
                    s.pop();
                    id--;
                } else {
                    ok = false;
                    break;
                }
            }
            if(!s.empty()) ok = false;
            if(ok) cout << "Yes\n";
            else cout << "No\n";
            //cout << ok ? "Yes\n" : "No\n";
        }
        cout << '\n';
    }
    return 0;
}
