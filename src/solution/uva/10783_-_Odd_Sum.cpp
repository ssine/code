#include <iostream>
using namespace std;

int main() {
    int kase; cin >> kase;
    for(int i = 1; i <= kase; i++) {
        int a, b, sum = 0;
        cin >> a >> b;
        for(int i = a; i <= b; i++) {
            if(i&1) sum += i;
        }
        cout << "Case " << i << ": " << sum << '\n';
    }
    return 0;
}
