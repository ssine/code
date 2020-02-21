#include <iostream>
#include <cstdio>
#include <cctype>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 100000 + 10;
const int INF = 0x7fffffff;
struct Node {
    int v;
    Node* l;
    Node* r;
    Node(int a) : v(a) {
        l = r = NULL;
    }
};
char s[maxn];

void print(Node* p) {
    printf("%d(", p->v);
    if(p->l) print(p->l);
    printf(",");
    if(p->r) print(p->r);
    printf(")");
}

int main() {
    freopen(".\\in&outputs\\in34", "r", stdin);
    freopen(".\\in&outputs\\out34", "w", stdout);
    int S;
    while(cin >> S) {
        int i = 0, lc = 1;
        while((s[i] = getchar()) != '(') i++; i++;
        while(lc) {
            s[i] = getchar();
            if(s[i] == '(') lc++;
            else if(s[i] == ')') lc--;
            else if(!isdigit(s[i]) && s[i] != '-') i--;
            i++;
        }
        s[i] = '\0';

        stack<Node*> ts;
        for(i = 0; s[i]; i++) {
            if(s[i] == '(') {
                if(s[i+1] == ')') {
                    ts.push(new Node(INF));
                    i++;
                } else {
                    int cur;
                    sscanf(&s[i+1], "%d", &cur);
                    ts.push(new Node(cur));
                }
            } else if (s[i] == ')') {
                Node* r = ts.top(); ts.pop();
                Node* l = ts.top(); ts.pop();
                Node* p = ts.top(); ts.pop();
                if(l->v != INF) p->l = l;
                else delete l;
                if(r->v != INF) p->r = r;
                else delete r;
                ts.push(p);
            }
        }
/*
        print(ts.top());
        cout << endl;
*/
        queue<Node*> q; q.push(ts.top());
        bool fd = false;
        while(!q.empty()) {
            Node* cur = q.front(); q.pop();
            if(!cur->l && !cur->r && cur->v == S) {
                fd = true;
                break;
            }
            if(cur->l) {
                cur->l->v += cur->v;
                q.push(cur->l);
            }
            if(cur->r) {
                cur->r->v += cur->v;
                q.push(cur->r);
            }
        }
/*
        print(ts.top());
        cout << endl;
*/
        if(fd) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
