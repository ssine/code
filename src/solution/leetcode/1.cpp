#include "leetcode.h"

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {};
  }
};

int main() {
  Solution sol;
  vector<int> arr = {2, 7, 11, 15};
  auto res = sol.twoSum(arr, 9);
  cout << res[0] << " " << res[1];
  return 0;
}
