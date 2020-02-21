#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
using namespace std;

struct change_point {
    int pos, height;
    bool is_add;
};

struct cpcmp {
    bool operator()(change_point& a, change_point& b) const {
        return a.pos > b.pos;
    }
};

priority_queue<change_point, vector<change_point>, cpcmp> pq;
multiset<int> state;

void show_state() {
    cout << "state: ";
    for(auto it = state.begin(); it != state.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}

int main() {
    freopen(".\\in&outputs\\in40", "r", stdin);
    freopen(".\\in&outputs\\out40", "w", stdout);

    // process input
    int l, h, r;
    change_point curp;
    while(cin >> l >> h >> r) {
        curp.pos = l; curp.height = h; curp.is_add = true;
        pq.push(curp);
        curp.pos = r; curp.height = h; curp.is_add = false;
        pq.push(curp);
    }

    // scan
    bool output_modify = true;
    state.insert(0);
    int cur_height = 0;
    while(!pq.empty()) {
        // show_state();
        curp = pq.top(); pq.pop();
        cur_height = *(state.rbegin());
        if(curp.is_add) {
            state.insert(curp.height);
            if(curp.height > cur_height) {
                // cout << "lift up: " << curp.height << endl;
                cur_height = curp.height;
                output_modify = true;
            }
        } else {
            // cout << *state.lower_bound(curp.height) << ' ';
            state.erase(state.lower_bound(curp.height));

            if(*(state.rbegin()) < cur_height) {
                // cout << "drop down: " << curp.height << endl;
                cur_height = *(state.rbegin());
                output_modify = true;
            }
        }
        if(pq.size() == 0 || curp.pos != pq.top().pos && output_modify) {
            cout << curp.pos << ' ' << cur_height;
            if(pq.size() != 0) cout << ' ';
            else cout << endl;
            output_modify = false;
        }
        // cout << cur_height << ' ';
    }

    return 0;
}
