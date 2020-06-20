#include "leetcode.h"

class Solution {
  vector<int64_t> sum;
  int lower, upper;

  int mergeSort(int l, int r) {
    if (r - l <= 1)
      return 0;
    int m = (l + r) / 2, count = 0;
    count += mergeSort(l, m);
    count += mergeSort(m, r);
    for (int i = l; i < m; i++) {
      auto rightLow = lower_bound(sum.begin() + m, sum.begin() + r, sum[i] + lower);
      auto rightHigh = upper_bound(sum.begin() + m, sum.begin() + r, sum[i] + upper);
      count += rightHigh - rightLow;
    }
    inplace_merge(sum.begin() + l, sum.begin() + m, sum.begin() + r);
    return count;
  }

public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    this->lower = lower;
    this->upper = upper;
    sum = vector<int64_t>(n + 1, 0);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + nums[i - 1];
    return mergeSort(0, n + 1);
  }
};

int main() {
  Solution sol;
  vector<int> arr = {-2, 5, -1};
  cout << sol.countRangeSum(arr, -2, 2) << endl;
  return 0;
}
