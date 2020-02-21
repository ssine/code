#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    int s[3];
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> s[0] >> s[1] >> s[2];
        sort(s, s+3);
        cout << "Case " << i+1 << ": " << s[1] << '\n';
    }
    return 0;
}
