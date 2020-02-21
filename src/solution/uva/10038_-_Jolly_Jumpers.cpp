#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    bool bit[3050];
    int n, i, a, b, ct;

    while(scanf("%d", &n) == 1) {
        ct = 0;
        memset(bit, 0, (n+1) * sizeof(bool));
        scanf("%d", &a);
        for(i = 1; i < n; i++) {
            if(i & 1) scanf("%d", &b);
            else scanf("%d", &a);
            bit[abs(a - b)] = 1;
        }
        for(i = 1; i < n; i++) if(bit[i]) ct++;
        if(ct == n - 1) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}
