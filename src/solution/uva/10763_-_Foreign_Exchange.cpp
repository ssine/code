#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

int main() {
    freopen(".\\in&outputs\\in6","r",stdin);
    freopen(".\\in&outputs\\out6","w",stdout);
    int n;
    while(cin >> n, n) {
        map<int, int> in, out;
        set<int> places;
        vector<int> place;
        int from, to;
        for(int i = 0; i < n; i++) {
            cin >> from >> to;

            if(out.count(from) == 0) out[from] = 1;
            else out[from] ++;
            if(in.count(to) == 0) in[to] = 1;
            else in[to] ++;

            if(places.count(from) == 0) {
                places.insert(from);
                place.push_back(from);
            }
            if(places.count(to) == 0) {
                places.insert(to);
                place.push_back(to);
            }
        }

        bool flag = true;
        for(int i = 0; i < place.size(); i++) {
            int cur = place[i];
            if(in[cur] != out[cur]) {
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
