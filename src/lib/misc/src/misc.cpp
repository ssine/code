#include "misc.h"
#include <vector>

using namespace std;

vector<int> getPMT(string s) {
  int n = s.size();
  // PMT[i] = length of longest common consecutive sub-sequence between s[0:i+1]'s postfix and s[0:i+1]'s prefix
  vector<int> PMT(n, 0);
  // i: postfix matcher, j: prefix matcher
  int i = 1, j = 0;
  while (i < n) {
    if (s[i] == s[j]) {
      PMT[i] = j + 1;
      i++;
      j++;
    } else {
      if (j == 0) {
        PMT[i] = 0;
        i++;
        j++;
      } else {
        j = PMT[j - 1];
      }
    }
  }
  return PMT;
}

int findSubstringPosition(string target, string pattern) {
  auto& PMT = getPMT(pattern);
  int n = target.size(), m = pattern.size();
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (target[i] == pattern[j]) {
      i++;
      j++;
    } else {
      if (j == 0) {
        i++;
      } else {
        j = PMT[j - 1];
      }
    }
  }
  if (j == m) {
    return i - m;
  } else {
    return -1;
  }
}
