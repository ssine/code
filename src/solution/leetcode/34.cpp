#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int l, r;

    auto l_it = lower_bound(nums.begin(), nums.end(), target);
    if (l_it == nums.end() || *l_it != target) l = -1;
    else l = l_it - nums.begin();

    auto r_it = upper_bound(nums.begin(), nums.end(), target);
    if (r_it == nums.begin() || *(r_it-1) != target) r = -1;
    else r = r_it - nums.begin() - 1;
    return {l, r};
  }
};

int main() {
  Solution sol;
  vector<int> v = {5,7,7,8,8,10};
  print_vector(sol.searchRange(v, 11));
  v = {};
  print_vector(sol.searchRange(v, 11));
  return 0;
}
