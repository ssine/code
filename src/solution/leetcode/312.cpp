#include "leetcode.h"

class Solution {
public:
  int maxCoins(vector<int> &nums) {
    const int n = nums.size();
    vector<vector<int>> maxIn(n + 1, vector<int>(n + 1, 0));
    for (int len = 1; len <= n; len++) {
      for (int start = 0; start + len <= n; start++) {
        int end = start + len;
        for (int last = start; last < end; last++) {
          int lastScore = nums[last] * (start == 0 ? 1 : nums[start - 1]) * (end >= n ? 1 : nums[end]);
          maxIn[start][end] = max(maxIn[start][end], lastScore + maxIn[start][last] + maxIn[last + 1][end]);
        }
      }
    }
    return maxIn[0][n];
  }
};

int main() {
  Solution sol;
  vector<int> arr = {3, 1, 5, 8};
  cout << sol.maxCoins(arr) << endl;
  return 0;
}
