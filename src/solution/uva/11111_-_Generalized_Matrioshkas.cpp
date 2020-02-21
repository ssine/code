#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int main() {
    freopen(".\\in&outputs\\in31", "r", stdin);
    freopen(".\\in&outputs\\out31", "w", stdout);
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        int cur;
        stack<int> s;
        stack<int> remain;
        bool ok = true;
        while(ss >> cur) {
            if(cur < 0) {
                if(remain.empty()) {
                    remain.push(-cur);
                    s.push(cur);
                } else if(remain.top() > -cur) {
                    remain.top() += cur;
                    s.push(cur);
                    remain.push(-cur);
                } else {
                    ok = false;
                    break;
                }
            } else {
                if(s.empty() || s.top() + cur != 0) {
                    ok = false;
                    break;
                } else {
                    s.pop();
                    remain.pop();
                }
            }
        }
        if(!s.empty()) ok = false;
        if(ok) cout << ":-) Matrioshka!\n";
        else cout << ":-( Try again.\n";
    }
    return 0;
}
