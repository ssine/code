#include "leetcode.h"
#include "utils.h"

class Solution {
 public:
  string minWindow(string s, string t) {
    map<char, int> charCount;
    for (char& c : t) {
      if (charCount.count(c) > 0) charCount[c] ++;
      else charCount[c] = 1;
    }
    string best = "";
    int l = 0, r = 0, numFulfilled = 0;
    while (r < s.size() || l < s.size()) {
      if (numFulfilled == charCount.size()) {
        char rm = s[l];
        if (charCount.count(rm) > 0) {
          charCount[rm]++;
          if (charCount[rm] == 1) {
            numFulfilled--;
          }
        }
        l++;
      } else if (r < s.size()) {
        char add = s[r];
        if (charCount.count(add) > 0) {
          charCount[add]--;
          if (charCount[add] == 0) {
            numFulfilled++;
          }
        }
        r++;
      } else {
        break;
      }
      if (numFulfilled == charCount.size() && (best == "" || r - l < best.size())) {
        best = s.substr(l, r - l);
      }
    }
    return best;
  }
};

int main() {
  Solution sol;
  cout << sol.minWindow("abc", "abc") << endl;
  return 0;
}
