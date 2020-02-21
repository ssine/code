#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#define DMAP(x1,x2) x1*m*n + x2
using namespace std;
const int maxc = 10;
const int maxr = 10000 + 10;
const int maxn = maxr * maxc;

map<string, int> lib;
vector<string> store;
int database[maxr][maxc];

map<int, int> strmap;

int main(){
    freopen(".\\in&outputs\\input65.txt","r",stdin);
    freopen(".\\in&outputs\\output65.txt","w",stdout);
    int n, m;
    while(cin >> n >> m){
        getchar();
        lib.clear();
        store.clear();

        for(int i = 0; i < n; i++){
            string cur;
            getline(cin, cur);
            int start, end = -1;
            for(int j = 0; j < m; j++) {
                start = end + 1;
                end = j == m-1 ? cur.length() : cur.find(',', start + 1);
                string sub = cur.substr(start, end - start);
                if(lib.count(sub)) database[i][j] = lib[sub];
                else {
                    lib[sub] = store.size();
                    store.push_back(sub);
                    database[i][j] = store.size() - 1;
                }
            }
        }

        /*for(int i = 0; i < store.size(); i++){  //test the map initializer
            cout << store[i] << " -> " << lib[store[i]] << '\n';
        }*/
        int flag, fc1, fc2, fr1, fr2;
        for(int c1 = 0; c1 < m; c1++) {
            flag = 0;
            for(int c2 = c1+1; c2 < m; c2++){
                strmap.clear();
                for(int i = 0; i < n; i++) {
                    int cur = DMAP(database[i][c1], database[i][c2]);
                    if(strmap.count(cur)) {
                        flag = 1;
                        fc1 = c1+1; fc2 = c2+1;
                        fr1 = strmap[cur]+1; fr2 = i+1;
                    } else {
                        strmap[cur] = i;
                    }
                    if(flag) break;
                }
            }
            if(flag) break;
        }

        if(flag) {
            cout << "NO\n" << fr1 << ' ' << fr2 << '\n' << fc1 << ' ' << fc2 << '\n';
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
