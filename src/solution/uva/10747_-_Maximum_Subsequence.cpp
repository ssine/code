#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 10000 + 10;

int seq[maxn];
bool cmp(int a, int b) {
    if(abs(a) != abs(b)) return abs(a) > abs(b);
    else return a > b;
}

int main() {
    freopen(".\\in&outputs\\in24","r",stdin);
    freopen(".\\in&outputs\\out24","w",stdout);
    int n, k;
    while(cin >> n >> k, n&&k) {
        for(int i = 0; i < n; i++) cin >> seq[i];
        sort(seq, seq + n, cmp);
        int neg = 0, product = 1, sum = 0;
        for(int i = 0; i < k; i++) {
            product *= seq[i];
            sum += seq[i];
            if(seq[i] < 0) neg++;
        }

        if(seq[k-1] == 0) {
            sort(seq, seq + n, greater<int>() );
            sum = 0;
            for(int i = 0; i < k; i++) sum += seq[i];
            cout << sum << '\n';
        } else if(k == n || neg%2 == 0) {
            cout << sum << '\n';
        } else {
            int last_n = 1, first_n = 1, last_p = -1, first_p = -1;
            for(int i = k-1; i >= 0; i--) {
                if(seq[i] < 0 && last_n ==1) last_n = seq[i];
                if(seq[i] > 0 && last_p == -1) last_p = seq[i];
                if(last_n != 1 && last_p != -1) break;
            }
            for(int i = k; i < n; i++) {
                if(seq[i] > 0 && first_p == -1) first_p = seq[i];
                if(seq[i] < 0 && first_n == 1) first_n = seq[i];
                if(first_n != 1 && first_p != -1) break;
            }

            if(last_p != -1 && first_n != 1 && first_p != -1) { //to possiblities
                double n_to_p = - first_p * 1.0 / last_n;
                double p_to_n = - first_n * 1.0 / last_p;
                if(p_to_n > n_to_p) {
                    sum = sum - last_p + first_n;
                } else {
                    sum = sum - last_n + first_p;
                }
            } else if(first_p != -1) { // change neg to positive
                sum = sum - last_n + first_p;
            } else if(last_p != -1 && first_n != 1) { //change pos to neg
                sum = sum - last_p + first_n;
            } else if((first_n == 1 && first_p == -1) || (last_p == -1 && first_p == -1)) {
                sort(seq, seq + n, greater<int>() );
                sum = 0;
                for(int i = 0; i < k; i++) sum += seq[i];
            }

            cout << sum << '\n';
        }
    }
    return 0;
}
