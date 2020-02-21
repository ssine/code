#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

const int maxn = 1000000 + 10;

int M[3][3][3] = {
    {{1, -2, 2},
     {2, -1, 2},
     {2, -2, 3}},
    {{1, 2, 2},
     {2, 1, 2},
     {2, 2, 3}},
    {{-1, 2, 2},
     {-2, 1, 2},
     {-2, 2, 3}}
};

bool sieve[maxn] = {0};
int cnt, npt;

void data_gen(int n) {

    memset(sieve, 0, sizeof(sieve[0])*(n+1));
    tuple<int, int, int> pt(3, 4, 5);
    queue< tuple<int, int, int> > ptq;
    if(n >= 5) ptq.push(pt);

    int a, b, c, an, bn, cn, newa, newb, newc;
    npt = 0;

    while(!ptq.empty()) {
        tuple<int, int, int> p = ptq.front();
        a = get<0>(p); b = get<1>(p); c = get<2>(p);
        ptq.pop();
        npt++;
        // generate new triples
        for(int i = 0; i < 3; i++) {
            newc = M[i][2][0]*a + M[i][2][1]*b + M[i][2][2]*c;
            if(newc <= n) {
                newa = M[i][0][0]*a + M[i][0][1]*b + M[i][0][2]*c;
                newb = M[i][1][0]*a + M[i][1][1]*b + M[i][1][2]*c;
                ptq.push(make_tuple(newa, newb, newc));
            }
        }

        // make the sieve
        an = a; bn = b; cn = c;
        while(cn <= n) {
            sieve[an] = true;
            sieve[bn] = true;
            sieve[cn] = true;
            an += a;
            bn += b;
            cn += c;
        }
    }

    cnt = 0;
    for(int i = 1; i <= n; i++) if(!sieve[i]) cnt++;

}

int main() {
    freopen(".\\in&outputs\\in41","r",stdin);
    freopen(".\\in&outputs\\out41","w",stdout);
    int n;
    while(cin >> n) {
        data_gen(n);
        cout << npt << ' ' << cnt << '\n';
    }
    return 0;
}
