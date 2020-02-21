#include <iostream>
using namespace std;

int main() {
    unsigned int a, b;
    int carry, n;
    while(cin >> a >> b, a + b) {
        carry = n = 0;
        while(a || b) {
            if(a%10 + b%10 + carry > 9) {
                n++;
                carry = 1;
            } else {
                carry = 0;
            }
            a /= 10;
            b /= 10;
        }
        if(n == 0) cout << "No carry operation.\n";
        else if(n == 1) cout << "1 carry operation.\n";
        else cout << n << " carry operations.\n";
    }
    return 0;
}
