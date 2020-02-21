#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n;

void putind(int indent) {
    for(int i = 0; i < indent; i++)
        cout << "  ";
}

void gen(string s, int ind) {
    int len = s.length();
    if(len == n) {
        putind(ind);
        cout << "writeln(";
        for(int i = 0; i < n-1; i++)
            cout << s[i] << ',';
        cout << s[n-1] << ")\n";
        return;
    }

    char* next = (char*)malloc(sizeof(char)*2);
    next[0] = 'a' + len; next[1] = 0;
    string newstr = s;
    putind(ind);
    cout << "if " << next << " < " << s[0] << " then\n";
    gen(string(newstr.insert(0, next).c_str()), ind + 1);
    for(int i = 1; i < len; i++) {
        putind(ind);
        cout << "else if " << next << " < " << s[i] << " then\n";
        newstr = s;
        gen(string(newstr.insert(i, next).c_str()), ind + 1);
    }
    putind(ind);
    cout << "else\n";
    newstr = s;
    gen(string(newstr.insert(len, next).c_str()), ind + 1);
}

int main() {
    freopen(".\\in&outputs\\in45", "r", stdin);
    freopen(".\\in&outputs\\out45", "w", stdout);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        if(i > 0) cout << '\n';
        cout << "program sort(input,output);\nvar\n";
        cin >> n;
        char c = 'a';
        for(int j = 0; j < n-1; j++)
            cout << c++ << ',';
        cout << c << " : integer;\nbegin\n  readln(";
        c = 'a';
        for(int j = 0; j < n-1; j++)
            cout << c++ << ',';
        cout << c << ");\n";
        gen(string("a"), 1);
        cout << "end.\n";
    }
    return 0;
}
