#include "leetcode.h"

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> charCount;
    for (char c : s) {
      if (charCount.count(c))
        charCount[c]++;
      else
        charCount[c] = 1;
    }
    int numOdd = 0;
    for (auto kv : charCount) {
      if (kv.second % 2 != 0)
        numOdd++;
    }
    return s.length() - max(0, numOdd - 1);
  }
};

int main() {
  Solution sol;
  cout << sol.longestPalindrome("Aa") << endl;
  return 0;
}
