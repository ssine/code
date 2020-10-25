#include "leetcode.h"

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    sort(points.begin(), points.end(), [](auto &lhs, auto &rhs) { return lhs[1] < rhs[1]; });
    int numArrows = 0, lastRightPos;
    bool bursted = false;
    for (auto &point : points) {
      if (bursted && point[0] <= lastRightPos)
        continue;
      numArrows++;
      lastRightPos = point[1];
      bursted = true;
    }
    return numArrows;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> arr = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  cout << sol.findMinArrowShots(arr) << endl;
  arr = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  cout << sol.findMinArrowShots(arr) << endl;
  arr = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  cout << sol.findMinArrowShots(arr) << endl;
  arr = {{1, 2}};
  cout << sol.findMinArrowShots(arr) << endl;
  arr = {{2, 3}, {2, 3}};
  cout << sol.findMinArrowShots(arr) << endl;
  arr = {};
  cout << sol.findMinArrowShots(arr) << endl;
  return 0;
}
