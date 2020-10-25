#include "leetcode.h"

class Solution {
public:
  int minMoves2(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int mid = nums[nums.size() / 2];
    return accumulate(nums.begin(), nums.end(), 0, [&](int acc, int e) { return acc + abs(e - mid); });
  }
};

int main() {
  Solution sol;
  return 0;
}
