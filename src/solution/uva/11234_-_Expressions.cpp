#include <iostream>
#include <string>
#include <cstdio>
#include <cctype>
#include <list>
#include <stack>
using namespace std;
struct Node {
    char v;
    Node* l;
    Node* r;
    Node(char c) : v(c) {
        l = r = NULL;
    }
};

int main() {
    freopen(".\\in&outputs\\in32", "r", stdin);
    freopen(".\\in&outputs\\out32", "w", stdout);
    int T; cin >> T; getchar();
    while(T--) {
        string p; cin >> p;
        stack<Node*> s;
        for(int i = 0; i < p.length(); i++) {
            if(islower(p[i])) {
                Node* cur = new Node(p[i]);
                s.push(cur);
            } else {
                Node* cur = new Node(p[i]);
                cur->r = s.top(); s.pop();
                cur->l = s.top(); s.pop();
                s.push(cur);
            }
        }

        list<Node*> bfs;
        stack<char> ot;
        bfs.push_back(s.top());
        while(!bfs.empty()) {
            Node* cur = bfs.front();
            ot.push(cur->v);
            if(cur->l != NULL) bfs.push_back(cur->l);
            if(cur->r != NULL) bfs.push_back(cur->r);
            bfs.pop_front();
        }
        while(!ot.empty()) {
            printf("%c", ot.top());
            ot.pop();
        }
        printf("\n");
    }
    return 0;
}
