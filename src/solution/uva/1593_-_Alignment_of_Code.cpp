#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
const int maxn = 1000 + 10;

string lines[maxn];
vector<string> words[maxn];
vector<int> length;

int main() {
    freopen(".\\in&outputs\\in3","r",stdin);
    freopen(".\\in&outputs\\out3","w",stdout);

    int i = 0, s, e;
    while(getline(cin, lines[i])) {

        for(int j = 0; j < lines[i].length(); j++) {
            if(lines[i][j] != ' ') {
                int l = 0;
                s = j;
                while(j < lines[i].length() && lines[i][j] != ' ') j++, l++;
                words[i].push_back(lines[i].substr(s, l));
                int n = words[i].size();
                if(length.size() < n) length.push_back(l);
                else length[n-1] = max(length[n-1], l);
            }
        }
        
        i++;
    }
    int n = i;

    for(i = 0; i < n; i++) {
        int size = words[i].size();
        for(int j = 0; j < size; j++) {
            cout << words[i][j];
            if(j < size - 1) {
                for(int k = words[i][j].length(); k < length[j]; k++) cout << ' ';
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
