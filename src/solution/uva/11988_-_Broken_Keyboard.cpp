#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 10;
char s[maxn];
int next_index[maxn], last;

int main() {
    freopen(".\\in&outputs\\in17","r",stdin);
    freopen(".\\in&outputs\\out17","w",stdout);
    int cur;
    while(scanf("%s", s+1) == 1) {
        int n = strlen(s+1);
        last = cur = 0;
        next_index[0] = 0;

        for(int i = 1; i <= n; i++) {
            char c = s[i];
            if(c == '[') cur = 0;
            else if(c == ']') cur = last;
            else {
                next_index[i] = next_index[cur];
                next_index[cur] = i;
                if(cur == last) last = i;
                cur = i;
            }
        }
        
        for(int i = next_index[0]; i != 0; i = next_index[i])
            printf("%c", s[i]);
        printf("\n");
    }
    return 0;
}
