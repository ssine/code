#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int min_abs_dif = numeric_limits<int>::max();
    int sum;
    for (size_t i = 0; i < nums.size(); i++) {
      int two_target = target - nums[i];
      size_t l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int trial = nums[l] + nums[r];
        if (abs(trial + nums[i] - target) < min_abs_dif) {
          sum = trial + nums[i];
          min_abs_dif = abs(sum - target);
        }
        if (trial < two_target) l++;
        else if (trial > two_target) r--;
        else return target;
      }
    }
    return sum;
  }
};

int main() {
  Solution sol;
  vector<int> v = {1, 1, 1, 0};
  cout << sol.threeSumClosest(v, -100) << endl;
  return 0;
}
