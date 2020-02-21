#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct Point{
    int x;
    int y;
    Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
    bool operator < (const Point& b) const {
        if(x != b.x) return x < b.x;
        return y < b.y;
    }
    bool operator > (const Point& b) const {
        if(x != b.x) return x > b.x;
        return y > b.y;
    }
};

int main() {
    freopen(".\\in&outputs\\in8","r",stdin);
    freopen(".\\in&outputs\\out8","w",stdout);
    freopen(".\\in&outputs\\out8","w",stderr);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        Point maxp = Point(-12000, 0), minp = Point(12000, 0);
        vector<Point> points(N);
        set<Point> ptset;
        for(int i = 0; i < N; i++) {
            cin >> points[i].x >> points[i].y;
            maxp = max(maxp, points[i]);
            minp = min(minp, points[i]);
            ptset.insert(points[i]);
        }

        int sum = maxp.x + minp.x; 
        if(maxp.x == minp.x) {
            cout << "YES\n";
            continue;
        }

        bool flag = false;
        for(int i = 0; i < N; i++) {
            if(!ptset.count(Point(sum - points[i].x, points[i].y))) {
                flag = true;
            }
        }
        if(flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
