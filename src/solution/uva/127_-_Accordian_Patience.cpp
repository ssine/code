#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <stack>
#include <list>
using namespace std;
struct Card {
    char face, suit;
    Card(char a, char b) : face(a), suit(b) {}
};
struct Pile {
    stack<Card> pl;
    Pile(char a, char b) {
        pl.push(Card(a, b));
    }
};

inline bool match(Pile& a, Pile& b) {
    return a.pl.top().face == b.pl.top().face || a.pl.top().suit == b.pl.top().suit;
}
inline void move(Pile& from, Pile& to) {
    Card cur = from.pl.top(); from.pl.pop();
    to.pl.push(cur);
}

int main() {
    freopen(".\\in&outputs\\in27", "r", stdin);
    freopen(".\\in&outputs\\out27", "w", stdout);
    string s, s1, s2;
    while(getline(cin, s1), s1 != "#") {
        getline(cin, s2);
        s = s1 + " " + s2;
        list<Pile> cd;
        for(int i = 0; i < 3; i++)
            cd.push_back(Pile('X'+i, 'X'+i));
        for(int i = 0; i < s.length(); i += 3) {
            cd.push_back(Pile(s[i], s[i+1]));
        }

        list<Pile>::iterator pr3 = cd.begin();
        list<Pile>::iterator pr1 = pr3; pr1++; pr1++;
        list<Pile>::iterator cur = pr1; cur++;
        while(cur != cd.end()) {
            if(match(*cur, *pr3)) {
                move(*cur, *pr3);
                if((*cur).pl.empty())
                    cur = cd.erase(cur);
                for(int i = 0 ; i < 3; i++) {
                    if(pr3 == cd.begin()) break;
                    pr3--; pr1--; cur--;
                }
            } else if(match(*cur, *pr1)) {
                move(*cur, *pr1);
                if((*cur).pl.empty())
                    cur = cd.erase(cur);
                for(int i = 0 ; i < 1; i++) {
                    if(pr3 == cd.begin()) break;
                    pr1--; pr3--; cur--;
                }
            } else {
                pr3++; pr1++; cur++;
            }
        }

        cout << cd.size() - 3;
        if(cd.size()-3 == 1) cout << " pile remaining:";
        else cout << " piles remaining:";
        cur = cd.begin(); cur++; cur++; cur++;
        for(; cur != cd.end(); cur++) {
            cout << ' ' << (*cur).pl.size();
        }
        cout << '\n';
    }
    return 0;
}
