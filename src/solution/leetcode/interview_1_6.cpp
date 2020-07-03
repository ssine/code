#include "leetcode.h"

// origin: https://leetcode-cn.com/problems/compress-string-lcci/
class Solution {
public:
  string compressString(string S) {
    string compressed = "";
    char lastChar = '\0';
    int lastLen = -1;
    for (char c : S) {
      if (c != lastChar) {
        if (lastLen != -1)
          compressed += to_string(lastLen);
        compressed += c;
        lastChar = c;
        lastLen = 1;
      } else {
        lastLen++;
      }
    }
    if (compressed.size() > 0)
      compressed += to_string(lastLen);
    if (compressed.size() < S.size())
      return compressed;
    else
      return S;
  }
};

int main() {
  Solution sol;
  cout << sol.compressString("") << endl;
  cout << sol.compressString("aabcccccaaa") << endl;
  cout << sol.compressString("abbccd") << endl;
  return 0;
}
