#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> n_tuples;
int l;

bool all_zero() {
    for(int i = 0; i < l; i++)
        if(n_tuples[i] != 0) return false;
    return true;
}

void next() {
    vector<int> tuples;
    tuples.resize(l);
    for(int i = 0; i < l; i++) {
        tuples[i] = abs(n_tuples[i] - n_tuples[(i+1)%l]);
    }
    n_tuples = tuples;
}

int main() {
    //freopen(".\\in&outputs\\in4","r",stdin);
    //freopen(".\\in&outputs\\out4","w",stdout);
    int n;
    cin >> n;
    while(n--) {
        set< vector<int> > his;
        cin >> l;
        n_tuples.resize(l);
        for(int i = 0; i < l; i++) cin >> n_tuples[i];
        
        if(all_zero()) {
            cout << "ZERO\n";
            continue;
        }
        
        his.insert(n_tuples);
        while(true) {
            next();
            if(his.count(n_tuples)) {
                cout << "LOOP\n";
                break;
            } else if(all_zero()) {
             cout << "ZERO\n";
                break;
            } else {
                his.insert(n_tuples);
            }
        }

    }
    return 0;
}
