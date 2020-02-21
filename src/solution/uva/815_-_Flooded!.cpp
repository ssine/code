#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
const int maxn = 30 * 30 + 5;

int sq[maxn], h[maxn];

int main() {
    freopen(".\\in&outputs\\in20","r",stdin);
    freopen(".\\in&outputs\\out20","w",stdout);
    int m, n, kase = 1;
    while(cin >> m >> n, m&&n) {
        int N = n * m;
        cin >> sq[0]; int minh = sq[0];
        for(int i = 1; i < N; i++) {
            cin >> sq[i];
            minh = min(minh, sq[i]);
        }
        /*for(int i = 0; i < N; i++) {
            sq[i] -= minh;
        }*/
        sort(sq, sq + N);
        while(sq[N-1] == sq[N-2]) N--;
        int lasth = N - 1; N = n*m;
        for(int i = 0; i < lasth; i++) {
            int j = i + 1;
            while(sq[j] == sq[i]) j++;
            int dif = sq[j] - sq[i];
            for(int k = i; k < j; k++) h[k] = dif;
        }

        /*for(int i = 0; i < N; i++) {
            cout << h[i] << ' ';
        }*/

        int curv = 0, v; cin >> v;
        int i;
        for(i = 0; i < lasth; ) {
            int j = i;
            while(sq[j] == sq[j+1]) j++;
            curv += 10*10 * h[i] * (j + 1);
            if(curv >= v) break;
            i = j + 1;
        }

        double level, pct;
        if(curv >= v) {
            int length = 1;
            while(sq[i] == sq[i + length]) length++;
            level = sq[i+length] - (curv - v) * 1.0 / (10*10*(i+length));
            pct = (i + length) * 1.0 / N * 100;
        } else {
            level = sq[N-1] + (v - curv) * 1.0 / (10*10*(N));
            pct = 100.00;
        }

        cout << "Region " << kase++ << '\n';
        cout << "Water level is " << fixed << setprecision(2) << level << " meters.\n";
        cout << fixed << setprecision(2) << pct << " percent of the region is under water.\n\n";
        
    }
    return 0;
}
