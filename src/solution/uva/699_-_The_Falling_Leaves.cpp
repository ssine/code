#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
const int maxn = 10000 + 10;
const int INF = 0x7fffffff;
struct Node {
    int v;
    Node* l;
    Node* r;
    Node(int a) : v(a) {
        l = r = NULL;
    }
};
int lp[maxn], l, r;

Node* buildTree() {
    int cur; cin >> cur;
    if(cur == -1) return NULL;
    Node* p = new Node(cur);
    p->l = buildTree();
    p->r = buildTree();
    return p;
}

void init() {
    memset(lp, 0, sizeof(lp));
    l = r = maxn / 2;
}

void fill(Node* p, int n) {
    lp[n] += p->v;
    l = min(l, n);
    r = max(r, n);
    if(p->l) fill(p->l, n - 1);
    if(p->r) fill(p->r, n + 1);
}

void print(int K) {
    cout << "Case " << K << ":\n";
    for(int i = l; i <= r; i++) {
        cout << lp[i];
        if(i < r) cout << ' ';
    }
    cout << endl << endl;
}

int main() {
    freopen(".\\in&outputs\\in38", "r", stdin);
    freopen(".\\in&outputs\\out38", "w", stdout);
    int K = 1;
    Node* p;
    while(p = buildTree()) {

        init();

        fill(p, maxn / 2);

        print(K++);
    }
    return 0;
}
