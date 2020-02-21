#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void reverse(string& s) {
    int l = s.length();
    for(int i = 0; i < l/2; i++) {
        swap(s[i], s[l-i-1]);
    }
}

bool isp(unsigned int a) {
    stringstream ss;
    string s;
    ss << a;
    ss >> s;
    ss.clear(); ss.str("");
    reverse(s);
    ss << s;
    unsigned int b; ss >> b;
    if(a == b) return true;
    else return false;
}

int main() {
    freopen(".\\in&outputs\\in11","r",stdin);
    freopen(".\\in&outputs\\out11","w",stdout);
    int N; cin >> N;
    while(N--) {
        unsigned int a, b, n = 1;
        stringstream ss;
        string s;
        cin >> a;
        ss << a;
        ss >> s;
        ss.str("");
        ss.clear();
        reverse(s);
        ss << s;
        ss >> b;
        a += b;
        while(!isp(a)) {
            ss.str("");
            ss.clear();
            ss << a;
            ss >> s;
            reverse(s);
            ss.str("");
            ss.clear();
            ss << s;
            ss >> b;
            a += b;
            n++;
        }
        cout << n << ' ' << a << '\n';
    }
    return 0;
}
