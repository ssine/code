#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct book{
    string title;
    string author;
    bool borrowed;
    bool returned;

    book(string a, string b) : title(a), author(b) {
        borrowed = false;
        returned = false;
    }
    bool operator < (const book& b) const {
        if(author != b.author) return author < b.author;
        else return title < b.title;
    }
};

vector<book> stock;

int search(string&);
int prebook(int);

void show() {
    for(int i = 0; i < stock.size(); i++) {
        cout << stock[i].title << " by " << stock[i].author << '\n';
        cout << stock[i].borrowed << " and " << stock[i].returned << '\n';
    }
    cout << "\n\n";
}

int main() {
    freopen(".\\in&outputs\\in13","r",stdin);
    freopen(".\\in&outputs\\out13","w",stdout);
    freopen(".\\in&outputs\\out13","w",stderr);
    string s;

    while(getline(cin, s), s != "END") {
        string title, author;
        int st = s.find('"');
        int ed = s.find('"', st + 1);
        title = s.substr(st, ed - st + 1);
        author = s.substr(ed + 5);
        stock.push_back(book(title, author));
    }
    sort(stock.begin(), stock.end());

    //show();

    while(getline(cin, s), s != "END") {
        if(s[0] == 'B') {
            s = s.substr(s.find(' ') + 1);
            int n = search(s);
            stock[n].borrowed = true;
        } else if(s[0] == 'R') {
            s = s.substr(s.find(' ') + 1);
            int n = search(s);
            stock[n].returned = true;
        } else if(s[0] == 'S') {
            for(int i = 0; i < stock.size(); i++) {
                if(stock[i].borrowed && stock[i].returned) {
                    stock[i].borrowed = stock[i].returned = false;
                    int pre = prebook(i);
                    if(pre == -1) cout << "Put " << stock[i].title << " first\n";
                    else cout << "Put " << stock[i].title << " after " << stock[pre].title << '\n';
                }
            }
            cout << "END\n";
        }
    }

    return 0;
}

int search(string& s) {
    for(int i = 0; i < stock.size(); i++) {
        if(stock[i].title == s) return i;
    }
    return 0;
}

int prebook(int n) {
    for(int i = n - 1; i >= 0; i--) {
        if(stock[i].borrowed == false) return i;
    }
    return -1;
}
