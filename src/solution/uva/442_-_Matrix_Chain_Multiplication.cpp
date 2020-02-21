#include <iostream>
#include <cctype>
#include <string>
#include <stack>
#define num(x) ((x) - ('A'))
using namespace std;
struct Matrix{
    int r, c;
    Matrix(int a = 0, int b = 0) : r(a), c(b) {}
    Matrix operator * (Matrix b) {
        return Matrix(r, b.c);
    }
} m[26];
int N;

int main() {
    freopen(".\\in&outputs\\in16","r",stdin);
    freopen(".\\in&outputs\\out16","w",stdout);
    cin >> N;
    for(int i = 0; i < N; i++) {
        string name;
        cin >> name;
        cin >> m[num(name[0])].r >> m[num(name[0])].c;
    }
        
    string s;
    while(cin >> s) {
        bool error = false;
        stack<Matrix> multiply;
        int sum = 0;
        for(int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) multiply.push(m[num(s[i])]);
            else if(s[i] == ')') {
                Matrix b = multiply.top(); multiply.pop();
                Matrix a = multiply.top(); multiply.pop();
                if(a.c != b.r) {error = true; break;}
                sum += a.r * a.c * b.c;
                multiply.push(a * b);
            }
        }
        if(error) cout << "error\n";
        else cout << sum << '\n';
    }
    return 0;
}
