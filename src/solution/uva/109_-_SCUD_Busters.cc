#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct point{
    int x, y;
    point(int x = 0, int y = 0) : x(x), y(y) {}
};

inline int cross(const point& a, const point& b) {
    return a.x*b.y - b.x*a.y;
}
inline double length(point& a) {
    return sqrt(a.x*a.x + a.y*a.y);
}
point operator - (point a, point b) {
    return point(a.x-b.x, a.y-b.y);
}
bool operator == (point a, point b) {
    return (a.x == b.x && a.y == b.y);
}

vector<point> current_country;
vector< vector<point> > country;
vector<bool> destroyed;

point basicp;
bool cmp(point a, point b) {
    double m1 = length(a);
    double m2 = length(b);
    double vd1 = a.x / m1, vd2 = b.x / m2;
    return (vd1 > vd2) || (vd1 == vd2 && m1 > m2);
}

void output_ct(vector<point>& v) {
    for(auto p : v) {
        cout << p.x << ' ' << p.y << endl;
    }
}

void process_convex() {
    point pmin = {501, 501};
    for(auto p : current_country) {
        if(p.y < pmin.y || p.y == pmin.y && p.x < pmin.x)
            pmin = p;
    }
    basicp = pmin;
    for(auto p = current_country.begin(); p != current_country.end();) {
        if(*p == basicp) p = current_country.erase(p);
        else {
            p->x -= basicp.x;
            p->y -= basicp.y;
            p++;
        }
    }

    

    //按各向量与横坐标之间的夹角排序  
    sort(current_country.begin(), current_country.end(), cmp);  
    // output_ct(current_country); cout << endl;
    //删除相同的向量  
    current_country.erase(unique(current_country.begin(), current_country.end()), current_country.end());  
    // output_ct(current_country); cout << endl;

    //计算得到首尾依次相联的向量  
    for (auto riter = current_country.rbegin();  
        riter != current_country.rend() - 1; ++riter) {  
            auto riNext = riter + 1;  
            //向量三角形计算公式  
            riter->x -= riNext->x, riter->y -= riNext->y;  
    }  
    //依次删除不在凸包上的向量  
    for (auto iter = current_country.begin() + 1; iter != current_country.end(); ++iter) {  
        //回溯删除旋转方向相反的向量，使用外积判断旋转方向  
        for (auto iLast = iter - 1; iLast != current_country.begin();) {  
            int v1 = iter->x * iLast->y, v2 = iter->y * iLast->x;  
            //如果叉积小于0，则无没有逆向旋转  
            //如果叉积等于0，还需判断方向是否相逆  
            if (v1 < v2 || (v1 == v2 && iter->x * iLast->x > 0 &&  
                iter->y * iLast->y > 0)) { break; }  
            //删除前一个向量后，需更新当前向量，与前面的向量首尾相连  
            //向量三角形计算公式  
            iter->x += iLast->x, iter->y += iLast->y;  
            iLast = (iter = current_country.erase(iLast)) - 1;  
        }  
    }  
    //将所有首尾相连的向量依次累加，换算成坐标  
    current_country.front().x += basicp.x, current_country.front().y += basicp.y;  
    for (auto iter = current_country.begin() + 1; iter != current_country.end(); ++iter) {  
        iter->x += (iter - 1)->x, iter->y += (iter - 1)->y;  
    }  
    //添加基点，全部的凸包计算完成  
    current_country.push_back(basicp);  
}

bool in_convex(point pos, vector<point>& ct) {
    int sign;
    for(int p = 0; p < ct.size(); p++) {
        point vec1 = ct[p] - pos, vec2 = ct[(p+1) % ct.size()] - pos;
        // cout << sign << ' ';
        if(p == 0) {
            sign = cross(vec1, vec2) & 0x80000000;
        } else {
            if((cross(vec1, vec2) & 0x80000000) != sign) {
                // cout << (cross(vec1, vec2) & 0x80000000) << '|' << sign << endl;
                return false;
            }
        }
    }
    // cout << "in!" << endl;
    return true;
}

void process_missile(point pos) {
    for(int i = 0; i < country.size(); i++) {
        if(in_convex(pos, country[i])) {
            // cout << i << " destroied!\n";
            destroyed[i] = true;
            break;
        }
    }
}

double get_area(int num) {
    double area = 0;
    for(auto it = country[num].begin()+1; it != country[num].end()-1; it++) {
        area += cross(*it - country[num][0], *(it+1) - country[num][0]);
    }
    return area / 2;
}



int main() {
    freopen(".\\in&outputs\\in44", "r", stdin);
    freopen(".\\in&outputs\\out44", "w", stdout);
    int n;
    point cur;
    while(cin >> n, n != -1) {
        current_country.clear();
        for(int i = 0; i < n; i++) {
            cin >> cur.x >> cur.y;
            current_country.push_back(cur);
        }
        process_convex();
        country.push_back(current_country);
        // output_ct(current_country);
        // cout << get_area(country.size()-1);
        // cout << endl;
        destroyed.push_back(false);
    }

    point SUCDpos;
    while(cin >> SUCDpos.x >> SUCDpos.y) {
        process_missile(SUCDpos);
    }

    double area = 0;
    for(int i = 0; i < country.size(); i++) {
        if(destroyed[i])
            area += get_area(i);
    }

    printf("%.2lf\n", area);
    return 0;
}
