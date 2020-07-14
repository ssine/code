#include "leetcode.h"

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    vector<int> ans;
    int idx = 0;
    while (idx < nums.size()) {
      if (nums[idx] != idx + 1 && nums[nums[idx] - 1] != nums[idx]) {
        swap(nums[idx], nums[nums[idx] - 1]);
      } else {
        idx++;
      }
    }
    for (idx = 0; idx < nums.size(); idx++) {
      if (nums[idx] != idx + 1) {
        ans.push_back(idx + 1);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {4, 3, 2, 7, 8, 2, 3, 1};
  print_vector(sol.findDisappearedNumbers(arr));
  return 0;
}
