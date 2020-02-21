#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
struct Node {
    char v;
    Node* c[4];
    Node(char a) : v(a) {
        c[0] = c[1] = c[2] = c[3] = NULL;
    }
};

Node* buildQTree(string& s) {
    stack<Node*> ts;
    for(int i = s.length() - 1; i >= 0; i--) {
        if(s[i] == 'p') {
            Node* p = new Node('p');
            for(int j = 0; j < 4; j++) {
                Node* cur = ts.top(); ts.pop();
                p->c[j] = cur;
            }
            ts.push(p);
        } else {
            Node* cur = new Node(s[i]);
            ts.push(cur);
        }
    }
    return ts.top();
}

Node* TAdd(Node* p1, Node* p2) {
    Node* cur = new Node('p');
    if(p1->v == 'f' || p2->v == 'f') {
        cur->v = 'f';
        return cur;
    }
    if(p1->v == 'e') return p2;
    if(p2->v == 'e') return p1;
    for(int i = 0; i < 4; i++) {
        cur->c[i] = TAdd(p1->c[i], p2->c[i]);
    }
    return cur;
}

int TSum(Node* p, int l) {
    if(p->v == 'f') return l;
    if(p->v == 'e') return 0;
    int s = 0;
    for(int i = 0; i < 4; i++) {
        s += TSum(p->c[i], l / 4);
    }
    return s;
}

void print(Node* p) {
    cout << p->v;
    if(p->c[0]) {
        cout << '(';
        for(int i = 0; i < 4; i++) {
            print(p->c[i]);
            if(i < 3) cout << ',';
        }
        cout << ')';
    }
}

int main() {
    freopen(".\\in&outputs\\in36", "r", stdin);
    freopen(".\\in&outputs\\out36", "w", stdout);
    int T; cin >> T;
    while(T--) {
        string s1, s2;
        cin >> s1 >> s2;
        
        Node* p1 = buildQTree(s1);
        Node* p2 = buildQTree(s2);

        Node* p = TAdd(p1, p2);

        //print(p); cout << endl;

        int ans = TSum(p, 1024);

        cout << "There are " << ans << " black pixels.\n";
    }
    return 0;
}
