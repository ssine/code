#include <iostream>
#include <cstdio>
using namespace std;
struct Node {
    int num;
    Node* next;
    Node* pre;
    Node(int a) : num(a) {
        next = pre = NULL;
    }
};

void remove(Node* del) {
    del->pre->next = del->next;
    del->next->pre = del->pre;
    delete del;
}

int main() {
    freopen(".\\in&outputs\\in28", "r", stdin);
    freopen(".\\in&outputs\\out28", "w", stdout);
    int N, k, m;
    while(cin >> N >> k >> m, N || k || m) {
        Node* head = new Node(0);
        Node* pre = head;
        for(int i = 1; i <= N; i++) {
            Node* cur = new Node(i);
            cur->pre = pre;
            pre->next = cur;
            pre = cur;
        }
        pre->next = head->next;
        head->next->pre = pre;

        int qn = N;
        Node* ctcloc = head->next;
        Node* cloc = head->next->pre;
        while(qn) {
            for(int i = 1; i < k; i++) ctcloc = ctcloc->next;
            for(int i = 1; i < m; i++) cloc = cloc->pre;
            if(qn < N) printf(",");
            if(cloc == ctcloc) {
                printf("%3d", cloc->num);
                ctcloc = ctcloc->next;
                cloc = cloc->pre;
                remove(cloc->next);
                qn--;
            } else {
                printf("%3d%3d", ctcloc->num, cloc->num);
                Node* cc = ctcloc; Node* c = cloc;
                if(ctcloc->next == c) ctcloc = c->next;
                else ctcloc = ctcloc->next;
                if(cloc->pre == cc) cloc = cc->pre;
                else cloc = cloc->pre;
                remove(cc);
                remove(c);
                qn -= 2;
            }
        }
        printf("\n");
    }
    return 0;
}
