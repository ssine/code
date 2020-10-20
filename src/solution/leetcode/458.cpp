#include "leetcode.h"

class Solution {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
  }
};

int main() {
  Solution sol;
  cout << sol.poorPigs(4, 15, 15) << endl;
  return 0;
}
