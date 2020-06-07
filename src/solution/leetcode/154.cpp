#include "leetcode.h"
#include "utils.h"

// the code is same as 153
class Solution {
  vector<int> nums;

public:
  // [l, r]
  int findIntervalMin(int l, int r) {
    while (l < r) {
      int m = (l + r) / 2;
      if (nums[l] < nums[r])
        return nums[l];
      if (nums[l] > nums[r]) {
        if (nums[m] >= nums[l]) {
          l = m + 1;
        } else {
          r = m;
        }
      } else if (nums[l] == nums[r]) {
        if (nums[m] > nums[l]) {
          l = m + 1;
        } else if (nums[m] < nums[r]) {
          r = m;
        } else {
          return min(findIntervalMin(l, m), findIntervalMin(m + 1, r));
        }
      }
    }
    return nums[l];
  }

  int findMin(vector<int> &nums) {
    this->nums = nums;
    return findIntervalMin(0, nums.size() - 1);
  }
};

int main() {
  Solution sol;
  // vector<int> arr = {2, 2, 2, 0, 1};
  // vector<int> arr = {2, 2, 2, 2, 2, 2, 1};
  // vector<int> arr = {1, 3, 5};
  // vector<int> arr = {3, 1, 1};
  vector<int> arr = {3, 1, 3, 3, 3};
  cout << sol.findMin(arr) << endl;
  return 0;
}
