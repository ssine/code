#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    auto quad_cmp = [] (vector<int> a, vector<int> b) {
      return a[0] == b[0] ? (a[1] == b[1] ? (a[2] == b[2] ? a[3] < b[3] : a[2] < b[2]) : a[1] < b[1]) : a[0] < b[0];
    };
    set<vector<int>, decltype(quad_cmp)> ans_set(quad_cmp);
    for (size_t i = 0; i < nums.size(); i++) {
      for (size_t j = i + 1; j < nums.size(); j++) {
        int two_target = target - nums[i] - nums[j];
        size_t l = j + 1, r = nums.size() - 1;
        while (l < r) {
          int trial = nums[l] + nums[r];
          if (trial < two_target) l++;
          else if (trial > two_target) r--;
          else {
            ans_set.insert({nums[i], nums[j], nums[l], nums[r]});
            l++; r--;
          }
        }
      }
    }
    return {ans_set.begin(), ans_set.end()};
  }
};

int main() {
  Solution sol;
  vector<int> v = {1, 0, -1, 0, -2, 2};
  print_matrix(sol.fourSum(v, 0));
  return 0;
}
