#include "leetcode.h"
#include "utils.h"

class Solution {
public:
  int trap(vector<int> &height) {
    if (height.size() <= 2)
      return 0;
    vector<int> local_extreme;
    if (height[0] > height[1])
      local_extreme.push_back(0);
    for (int i = 1; i < height.size() - 1; i++) {
      if (height[i] >= height[i - 1] && height[i] >= height[i + 1])
        local_extreme.push_back(i);
    }
    if (*(height.end() - 2) < height.back())
      local_extreme.push_back(height.size() - 1);

    int ans = 0;
    for (int i = 0; i < local_extreme.size() - 1;) {
      int idxl = local_extreme[i], idxr;
      int r_max_h = -1;
      for (int j = i + 1; j < local_extreme.size(); j++) {
        int _idx = local_extreme[j], _h = height[_idx];
        if (_h >= height[idxl]) {
          idxr = _idx;
          i = j;
          break;
        }
        if (_h > r_max_h) {
          r_max_h = _h;
          idxr = _idx;
          i = j;
        }
      }
      int h = min(height[idxl], height[idxr]);
      for (int j = idxl + 1; j < idxr; j++) {
        if (height[j] < h)
          ans += h - height[j];
      }
    }

    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 3};
  cout << sol.trap(h) << endl;
  h = {5, 4, 1, 2};
  cout << sol.trap(h) << endl;
  h = {5, 2, 1, 2, 1, 5};
  cout << sol.trap(h) << endl;
  h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << sol.trap(h) << endl;
  h = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
  cout << sol.trap(h) << endl;
  return 0;
}
