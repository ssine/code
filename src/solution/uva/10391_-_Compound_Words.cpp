#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
using namespace std;
const int maxn = 120000 + 10;

vector<string> dict(maxn);
set<string> dictset;
int n;

int main() {
    freopen(".\\in&outputs\\in7","r",stdin);
    freopen(".\\in&outputs\\out7","w",stdout);
    int i = 0, l;
    while(cin >> dict[i]) {
        dictset.insert(dict[i]);
        i++;
    }

    bool flag;
    n = i;
    for(i = 0; i < n; i++) {
        flag = false;
        for(int j = 1; j < dict[i].length(); j++) {
            if(dictset.count(dict[i].substr(0,j)) && dictset.count(dict[i].substr(j))) {
                flag = true;
                break;
            }
        }
        if(flag) cout << dict[i] << '\n';
    }

    return 0;
}
