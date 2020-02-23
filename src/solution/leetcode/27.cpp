#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      if (nums[l] == val) {
        swap(nums[l], nums[r]);
        r--;
      } else {
        l++;
      }
    }
    return r + 1;
  }
};

int main() {
  Solution sol;
  vector<int> v = {1};
  cout << sol.removeElement(v, 1) << endl;
  print_vector(v);
  return 0;
}
