#include <iostream>
#include <string>
#include <cstdio>
#include <stack>
using namespace std;

bool match(char l, char r) {
    return l == '(' && r == ')' || l == '[' && r == ']';
}
int main() {
    freopen(".\\in&outputs\\in30", "r", stdin);
    freopen(".\\in&outputs\\out30", "w", stdout);
    int T; cin >> T; getchar();
    while(T--) {
        string p; getline(cin, p);
        stack<char> s;
        bool ok = true;
        for(int i = 0; i < p.length(); i++) {
            if(p[i] == '(' || p[i] == '[') {
                s.push(p[i]);
            } else if(s.empty()) {
                ok = false;
                break;
            } else if (match(s.top(), p[i])) {
                s.pop();
            } else {
                ok = false;
                break;
            }
        }
        if(!s.empty()) ok = false;
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
