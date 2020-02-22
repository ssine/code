#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string s, p;

  bool match(int spos, int ppos) {
    if (spos == s.length() && ppos == p.length())
      return true;
    if (ppos == p.length())
      return false;

    char c = p[ppos];
    int num = 1;
    bool inf = false;
    while (ppos++ < p.length()) {
      if (p[ppos] == '*')
        inf = true, num--;
      else if (p[ppos] == c)
        num++;
      else
        break;
    }

    if (c == '.') {
      if (spos + num > s.length())
        return false;
    } else {
      for (int i = 0; i < num; i++)
        if (spos + i >= s.length() || s[spos + i] != c)
          return false;
    }

    if (inf) {
      for (int i = 0; spos + num + i <= s.length(); i++) {
        if (match(spos + num + i, ppos))
          return true;
        if (c != '.' && s[spos + num + i] != c)
          break;
      }
      return false;
    } else {
      return match(spos + num, ppos);
    }
  }

  bool isMatch(string _s, string _p) {
    s = _s;
    p = _p;
    return match(0, 0);
  }
};

int main() {
  string s = "mississippi";
  string p = "mis*is*.p*.";
  Solution solver = Solution();
  cout << solver.isMatch(s, p);
  return 0;
}
