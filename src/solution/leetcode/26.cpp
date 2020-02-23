#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    return unique(nums.begin(), nums.end()) - nums.begin();
  }
};

int main() {
  Solution sol;
  vector<int> v = {0,0,1,1,1,2,2,3,3,4};
  cout << sol.removeDuplicates(v) << endl;
  print_vector(v);
  return 0;
}
