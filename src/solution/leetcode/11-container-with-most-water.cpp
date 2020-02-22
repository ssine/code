#include "leetcode.h"

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int max_area = 0;
    while (l < r) {
      int h = min(height[l], height[r]);
      int area = h * (r - l);
      max_area = max(max_area, area);
      while (l < height.size() && height[l] <= h) l++;
      while (r >= 0 && height[r] <= h) r--;
    }
    return max_area;
  }
};

int main() {
  Solution sol;
  vector<int> a{1,8,6,2,5,4,8,3,7};
  cout << sol.maxArea(a) << endl;
  return 0;
}
