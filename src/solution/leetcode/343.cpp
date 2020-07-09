#include "leetcode.h"

constexpr auto generate_answer() {
  std::array<int, 59> answer = {0};
  answer[2] = 1;
  for (int i = 3; i < 59; i++) {
    for (int j = 2; j < i; j++) {
      answer[i] = max(answer[i], answer[j] * (i - j));
      answer[i] = max(answer[i], j * (i - j));
    }
  }
  return answer;
}

class Solution {
public:
  int integerBreak(int n) {
    constexpr auto ans = generate_answer();
    return ans[n];
  }
};

int main() {
  Solution sol;
  for (int i = 2; i < 59; i++)
    cout << i << ": " << sol.integerBreak(i) << endl;
  return 0;
}
