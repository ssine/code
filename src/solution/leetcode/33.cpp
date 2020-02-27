#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, m;
    while (l <= r) {
      m = (l + r) / 2;
      int n_m = nums[m], n_l = nums[l], n_r = nums[r];
      if (n_m == target) return m;
      if (n_l < n_r) {
        if (n_m < target) l = m + 1;
        else r = m - 1;
      } else if (n_m >= n_l) {
        if (target >= n_l && target < n_m) r = m - 1;
        else l = m + 1;
      } else {
        if (target > n_m && target <= n_r) l = m + 1;
        else r = m - 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> v = {4,5,6,7,0,1,2};
  cout << sol.search(v, 0) << endl;
  cout << sol.search(v, 3) << endl;
  v = {3, 5, 1};
  cout << sol.search(v, 3) << endl;
  v = {5, 1, 3};
  cout << sol.search(v, 5) << endl;
  v = {3, 1};
  cout << sol.search(v, 1) << endl;
  return 0;
}
