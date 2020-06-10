#include "leetcode.h"
#include "utils.h"

struct BuildingCorner {
  int x, y;
  bool isLeftEdge;
  bool operator<(const BuildingCorner &lhs) { return x < lhs.x; }
};

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    if (buildings.size() == 0)
      return {};
    vector<BuildingCorner> corners;
    for (auto &building : buildings) {
      corners.push_back({building[0], building[2], true});
      corners.push_back({building[1], building[2], false});
    }
    sort(corners.begin(), corners.end());
    // all heights at current position
    multiset<int> heights = {0};
    vector<vector<int>> ans;
    int lastX = -1;
    for (auto &corner : corners) {
      if (lastX != -1 && corner.x != lastX) {
        if (ans.size() == 0 || ans.back()[1] != *heights.rbegin())
          ans.push_back({lastX, *heights.rbegin()});
      }
      if (corner.isLeftEdge) {
        heights.insert(corner.y);
      } else {
        heights.erase(heights.lower_bound(corner.y));
      }
      lastX = corner.x;
    }
    ans.push_back({corners.back().x, 0});
    return ans;
  }
};

int main() {
  Solution sol;
  // ans: {{2, 10}, {3, 15}, {7, 12}, {12, 0}, {15, 10}, {20, 8}, {24, 0}}
  vector<vector<int>> arr = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  // vector<vector<int>> arr = {};
  print_matrix(sol.getSkyline(arr));
  return 0;
}
