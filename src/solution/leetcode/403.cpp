#include "leetcode.h"

class Solution {
  set<pair<int, int>> triedPositionDistance; // failed combinations
  set<int> stones;
  int end;

public:
  // is it possible to jump to end standing on stone[position] and jump nextJump units next time?
  bool test(int position, int nextJump) {
    if (position + nextJump == end)
      return true;
    auto pair = make_pair(position, nextJump);
    if (triedPositionDistance.count(pair))
      return false;
    if (!stones.count(position + nextJump)) {
      triedPositionDistance.insert(pair);
      return false;
    }
    for (int i = -1; i <= 1; i++) {
      if (nextJump + i > 0 && test(position + nextJump, nextJump + i))
        return true;
    }
    triedPositionDistance.insert(pair);
    return false;
  }

  bool canCross(vector<int> &stones) {
    end = stones.back();
    this->stones = {stones.begin(), stones.end()};
    return test(0, 1);
  }
};

int main() {
  Solution sol;
  // vector<int> arr = {0, 1, 3, 5, 6, 8, 12, 17};
  vector<int> arr = {0,1,2,3,4,8,9,11};
  cout << sol.canCross(arr) << endl;
  return 0;
}
