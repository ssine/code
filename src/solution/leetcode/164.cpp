#include "leetcode.h"
#include "utils.h"

class Solution {
public:
  int maximumGap(vector<int> &nums) {
    size_t n = nums.size();
    if (n < 2)
      return 0;
    int l = *min_element(nums.begin(), nums.end());
    int r = *max_element(nums.begin(), nums.end());
    if (l == r)
      return 0;
    double interval = static_cast<double>(r - l) / (n - 1);
    vector<int> holeMin(n, numeric_limits<int>::max());
    vector<int> holeMax(n, numeric_limits<int>::min());
    vector<bool> vis(n, false);
    for (size_t i = 0; i < n; i++) {
      int cur = nums[i];
      int idx = (cur - l) / interval;
      holeMax[idx] = max(holeMax[idx], cur);
      holeMin[idx] = min(holeMin[idx], cur);
      vis[idx] = true;
    }
    int maxGap = 0, lastMax = holeMax[0];
    for (size_t i = 1; i < n; i++) {
      if (!vis[i])
        continue;
      maxGap = max(maxGap, holeMin[i] - lastMax);
      lastMax = holeMax[i];
    }
    return maxGap;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {3, 3, 3, 3, 3, 4, 4, 4, 4};
  cout << sol.maximumGap(arr) << endl;
  return 0;
}
