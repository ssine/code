#include "leetcode.h"

class Solution {
  int n;
  int nLen;
  string nStr;

public:
  int countFull(int lenPrefix, int lenTotal) {
    int num = lenTotal - lenPrefix;
    if (num < 0)
      return 0;
    int count = 0;
    int nChilds = 1;
    do {
      count += nChilds;
      nChilds *= 10;
    } while (num--);
    return count;
  }

  int countTotalNumberIn(int p) {
    int prefixLen = to_string(p).size();
    int nPrefix;
    from_chars(nStr.data(), nStr.data() + prefixLen, nPrefix);
    if (p == nPrefix) {
      if (p == n)
        return 1;
      int nextNPrefix;
      from_chars(nStr.data(), nStr.data() + prefixLen + 1, nextNPrefix);
      int nextN = nStr.data()[prefixLen] - '0';

      return 1 + nextN * countFull(prefixLen + 1, nLen) + countTotalNumberIn(nextNPrefix) +
             (9 - nextN) * countFull(prefixLen + 1, nLen - 1);
    } else if (p < nPrefix) {
      return countFull(prefixLen, nLen);
    } else if (p > nPrefix) {
      return countFull(prefixLen, nLen - 1);
    }
    return -1;
  }

  int findKthNumberIn(int p, int k) {
    /**
     * (prefix, k) -> k-th number in range
     * e.g. (52, k) -> k-th number in numbers like 52xxx (including 52)
     */
    if (p != 0 && k == 1)
      return p;
    if (p != 0)
      k -= 1;
    int begin = p == 0 ? 1 : 0;
    for (int i = begin; i <= 9; i++) {
      int nextPrefix = p * 10 + i;
      int numInRange = countTotalNumberIn(nextPrefix);
      if (k <= numInRange) {
        return findKthNumberIn(nextPrefix, k);
      } else {
        k -= numInRange;
      }
    }
    return -1;
  }

  int findKthNumber(int n, int k) {
    this->n = n;
    nStr = to_string(n);
    nLen = nStr.size();
    return findKthNumberIn(0, k);
  }
};

int main() {
  Solution sol;
  // cout << sol.findKthNumber(13, 2) << endl;
  // cout << sol.findKthNumber(13, 6) << endl;
  cout << sol.findKthNumber(1000000000, 11) << endl;
  return 0;
}
