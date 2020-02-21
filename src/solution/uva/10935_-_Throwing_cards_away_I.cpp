#include <iostream>
#include <deque>
using namespace std;

int main() {
    freopen(".\\in&outputs\\in5","r",stdin);
    freopen(".\\in&outputs\\out5","w",stdout);
    int n;
    while(cin >> n, n) {
        deque<int> deck;
        for(int i = n; i > 0; i--) deck.push_back(i);
        cout << "Discarded cards:";
        while(deck.size() > 1) {
            cout << ' ' << deck.back();
            if(deck.size() > 2) cout << ",";
            deck.pop_back();
            deck.push_front(deck.back());
            deck.pop_back();
        }
        cout << "\nRemaining card: " << deck.front() << '\n';
    }
    return 0;
}
