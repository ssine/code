#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main() {
    freopen(".\\in&outputs\\in9","r",stdin);
    freopen(".\\in&outputs\\out9","w",stdout);
    freopen(".\\in&outputs\\out9","w",stderr);
    int kase;
    cin >> kase;
    while(kase--) {
        int N, curp, cur, val;
        priority_queue<int> pq;
        deque<int> dq;
        cin >> N >> curp;
        for(int i = 0; i < N; i++) {
            cin >> cur;
            if(i == curp) val = cur;
            dq.push_back(cur);
            pq.push(cur);
        }

        int min = 1;
        while( !(curp == 0 && val == pq.top()) ) {
            if(dq.front() < pq.top()) {
                dq.push_back(dq.front());
                dq.pop_front();
                curp--;
                if(curp < 0) curp = N - 1;
            } else {
                min++;
                dq.pop_front();
                pq.pop();
                N--; curp--;
                if(curp < 0) curp = N - 1;
            }
        }
        cout << min << '\n';
    }
    return 0;
}
