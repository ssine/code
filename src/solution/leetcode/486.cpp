#include "leetcode.h"

class Solution {
public:
  bool PredictTheWinner(vector<int> &nums) {
    map<tuple<int, int, bool>, int> memory;

    function<int(int, int, bool)> maxScore = [&](int l, int r, bool isFirst) {
      auto key = make_tuple(l, r, isFirst);
      if (memory.count(key))
        return memory[key];

      if (r - l == 1)
        if (isFirst)
          return memory[key] = nums[l];
        else
          return memory[key] = 0;

      if (isFirst)
        return memory[key] = max(maxScore(l + 1, r, false) + nums[l], maxScore(l, r - 1, false) + nums[r - 1]);
      else
        return memory[key] = min(maxScore(l + 1, r, true), maxScore(l, r - 1, true));
    };

    int sum = accumulate(nums.begin(), nums.end(), 0), ms = maxScore(0, nums.size(), true);
    return ms >= sum - ms;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 5, 2};
  // vector<int> arr = {1, 5, 233, 7};
  cout << sol.PredictTheWinner(arr) << endl;
  return 0;
}
