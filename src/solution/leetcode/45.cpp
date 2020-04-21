#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int jump(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    vector<int> stepBoundary;
    stepBoundary.push_back(1);
    int idx = 0;
    for (int step = 0; step < stepBoundary.size(); step++) {
      int boundIdx = stepBoundary[step];
      int maxBound = -1;
      for (; idx < boundIdx; idx++) {
        maxBound = max(maxBound, idx + nums[idx] + 1);
      }
      if (maxBound >= nums.size()) return step + 1;
      stepBoundary.push_back(maxBound);
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {2, 3, 1, 1, 4};
  // cout << sol.jump(arr) << endl;
  arr = {1, 1, 1, 1};
  cout << sol.jump(arr) << endl;
  return 0;
}