#include "leetcode.h"
#include "number.h"
#include "utils.h"

typedef tuple<int64_t, int64_t, int64_t> line;
typedef pair<int, int> point;

class Solution {
public:
  line computeLine(int x1, int y1, int x2, int y2) {
    int64_t a = y2 - y1;
    int64_t b = x1 - x2;
    int64_t c = static_cast<int64_t>(x2) * y1 - static_cast<int64_t>(x1) * y2;
    if (a < 0) {
      a = -a;
      b = -b;
      c = -c;
    }
    int64_t d = gcd({a, b, c});
    if (d != 0) {
      a /= d;
      b /= d;
      c /= d;
    }
    return make_tuple(a, b, c);
  }

  int maxPoints(vector<vector<int>> &points) {
    map<point, int> pointCount;
    for (auto pArr : points) {
      auto p = make_pair(pArr[0], pArr[1]);
      if (pointCount.count(p) == 0) {
        pointCount[p] = 1;
      } else {
        pointCount[p]++;
      }
    }
    int n = pointCount.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return pointCount.begin()->second;
    map<line, set<point>> linePoints;
    for (auto it = pointCount.begin(); it != pointCount.end(); it++) {
      for (auto jt = pointCount.begin(); jt != it; jt++) {
        line l = computeLine(it->first.first, it->first.second, jt->first.first, jt->first.second);
        if (linePoints.count(l) == 0) {
          linePoints[l] = set<point>();
        }
        linePoints[l].insert(it->first);
        linePoints[l].insert(jt->first);
      }
    }
    int maxCount = 0;
    for (const auto &[l, pts] : linePoints) {
      int npt = 0;
      for (const auto& pt : pts) {
        npt += pointCount[pt];
      }
      maxCount = max(maxCount, npt);
    }
    return maxCount;
  }
};

int main() {
  Solution sol;
  // vector<vector<int>> arr = {{1, 1}, {1, 1}, {2, 2}, {2, 2}};
  // vector<vector<int>> arr = {{0,0},{1,65536},{65536,0}};
  vector<vector<int>> arr = {{0, 0}, {0, 0}, {1, 1}, {2, 2}};
  cout << sol.maxPoints(arr) << endl;
  return 0;
}
