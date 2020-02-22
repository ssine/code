#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (size_t i = 0; i < nums.size(); i++) {
      int target = - nums[i];
      if (target < 0) break;
      size_t l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int trial = nums[l] + nums[r];
        if (trial < target) l++;
        else if (trial > target) r--;
        else {
          int nl = nums[l], nr = nums[r];
          ans.push_back({-target, nl, nr});
          while (l < r && nums[l] == nl) l++;
          while (l < r && nums[r] == nr) r--;
        }
      }
      while (i + 1 < nums.size() && nums[i + 1] == -target) i++;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> v = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
  print_matrix(sol.threeSum(v));
  return 0;
}
