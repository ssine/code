#include "leetcode.h"

class Solution {
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
      return false;
    map<pair<int, unsigned long>, bool> memory;
    function<bool(int, bitset<21> &)> dfs = [&](int total, bitset<21> &pool) {
      auto pair = make_pair(total, pool.to_ulong());
      if (memory.count(pair))
        return memory[pair];

      for (int i = 1; i <= maxChoosableInteger; i++)
        if (pool.test(i) && total - i <= 0)
          return memory[pair] = true;

      for (int i = 1; i <= maxChoosableInteger; i++)
        if (pool.test(i)) {
          auto bs = pool;
          bs.reset(i);
          if (!dfs(total - i, bs))
            return memory[pair] = true;
        }

      return memory[pair] = false;
    };
    bitset<21> state;
    state.set();
    return dfs(desiredTotal, state);
  }
};

int main() {
  Solution sol;
  cout << sol.canIWin(10, 11) << endl;
  cout << sol.canIWin(10, 0) << endl;
  cout << sol.canIWin(10, 1) << endl;
  cout << sol.canIWin(10, 40) << endl;
  cout << sol.canIWin(5, 50) << endl;
  cout << sol.canIWin(20, 300) << endl;
  return 0;
}
