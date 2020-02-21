#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <sstream>
using namespace std;
const int maxn = 10000 + 10;
const int INF = 0x7fffffff;
struct Node {
    int v, sum;
    Node* l;
    Node* r;
    Node(int a) : v(a), sum(a) {
        l = r = NULL;
    }
};

int preot[maxn], posot[maxn];

Node* buildTree(int prel, int prer, int posl, int posr) {
    Node* p = new Node(posot[posr]);
    int i;
    for(i = prel; i <= prer; i++)
        if(preot[i] == posot[posr]) break;
    if(i != prel)
        p->l = buildTree(prel, i-1, posl, posl+i-prel-1);
    if(i < prer)
        p->r = buildTree(i+1, prer, posl+i-prel, posr-1);
    return p;
}

int main() {
    freopen(".\\in&outputs\\in35", "r", stdin);
    freopen(".\\in&outputs\\out35", "w", stdout);
    string s1, s2;
    while(getline(cin, s1)) {
        getline(cin, s2);
        stringstream ss1(s1);
        int i = 0;
        while(ss1 >> preot[i]) i++;
        stringstream ss2(s2);
        i = 0;
        while(ss2 >> posot[i]) i++;
        int len = i;
        Node* p = buildTree(0, len-1, 0, len-1);
        
        p->sum = p->v;
        queue<Node*> q; q.push(p);
        int min = INF, minv = INF;
        while(!q.empty()) {
            Node* cur = q.front(); q.pop();
            if(!cur->l && !cur->r) {
                if(cur->sum < minv) {
                    minv = cur->sum;
                    min = cur->v;
                }
            }
            if(cur->l) {
                cur->l->sum += cur->sum;
                q.push(cur->l);
            }
            if(cur->r) {
                cur->r->sum += cur->sum;
                q.push(cur->r);
            }
        }

        cout << min << endl;
    }
    return 0;
}
