#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_COL = 100;
const int MAX_ROW = 10;

int map[MAX_ROW][MAX_COL];
int dist[MAX_ROW][MAX_COL];
int dir[MAX_ROW][MAX_COL];

int r, c;

int argmin(int* a, int n, int curpos) {
    int min = 0x7fffffff;
    int pos = -1;
    for(int i = 0; i < n; i++)
        if(a[i] < min)
            min = a[i], pos = i;
    if(curpos == 0) {
        if(a[2] == min) pos = 2;
        if(a[1] == min) pos = 1;
    } else if(curpos == r - 1) {
        if(a[2] == min) pos = 2;
    }
    return pos;
}

void print_dist() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%3d ", dist[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}
void print_dir() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%3d ", dir[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    while(cin >> r >> c) {
        for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> map[i][j];

        for(int i = 0; i < r; i++)
            dist[i][c-1] = map[i][c-1];

        // dp
        for(int j = c-2; j >= 0; j--) {
            for(int i = 0; i < r; i++) {
                int ar[] = {dist[(i-1+r)%r][j+1], dist[i][j+1], dist[(i+1)%r][j+1]};
                int di = argmin(ar, 3, i) - 1;
                // if(i == r-1) cout << "~ " << di << endl;
                dir[i][j] = di;
                dist[i][j] = dist[(i+di+r)%r][j+1] + map[i][j];
            }
        }
        // print_dist();
        // print_dir();

        int min = 0x7fffffff;
        int pos;
        for(int i = 0; i < r; i++) {
            if(dist[i][0] < min)
                min = dist[i][0], pos = i;
        }

        int i = pos;
        for(int j = 0; j < c; j++) {
            cout << i+1;
            if(j != c-1) cout << ' ';
            i = (i+dir[i][j]+r)%r;
        }

        cout << endl << min << endl;

    }
    return 0;
}
