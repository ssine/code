#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 65536 + 20;
struct Song{
    int id;
    float ratio;
    bool operator < (Song b) const {
        if(ratio != b.ratio) return ratio < b.ratio;
        else return id < b.id;
    }
};

Song song[maxn];

int main() {
    freopen(".\\in&outputs\\in23","r",stdin);
    freopen(".\\in&outputs\\out23","w",stdout);
    int N;
    while(cin >> N) {
        float l, f;
        for(int i = 0; i < N; i++) {
            cin >> song[i].id >> l >> f;
            song[i].ratio = l / f;
        }
        sort(song, song + N);

        int num; cin >> num;
        cout << song[num - 1].id << '\n';
    }
    return 0;
}
