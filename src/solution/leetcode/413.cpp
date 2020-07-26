#include "leetcode.h"

class Solution {
  // given length of arithmetic array, return num of all sub arithmetic arrays
  int getSubarrayNum(int len) {
    // (len - 3 + 1) + (len - 4 + 1) + ... + (len - len + 1)
    // = len * (len - 3 + 1) - (len + 3) * (len - 3 + 1) / 2 + (len - 3 + 1)
    // = (len - (len + 3) / 2 + 1) * (len - 3 + 1)
    if (len < 3)
      return 0;
    return (len + 1) * (len - 2) - (len + 3) * (len - 2) / 2;
  }

public:
  int numberOfArithmeticSlices(vector<int> &A) {
    if (A.size() < 3)
      return 0;
    int numConsecutiveDiff = 1, numTotalSubArray = 0;
    int lastDiff = A[1] - A[0];
    for (int idx = 2; idx < A.size(); idx++) {
      if (A[idx] - A[idx - 1] == lastDiff) {
        numConsecutiveDiff++;
      } else {
        numTotalSubArray += getSubarrayNum(numConsecutiveDiff + 1);
        numConsecutiveDiff = 1;
        lastDiff = A[idx] - A[idx - 1];
      }
    }
    numTotalSubArray += getSubarrayNum(numConsecutiveDiff + 1);
    return numTotalSubArray;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 2, 3, 5};
  cout << sol.numberOfArithmeticSlices(arr) << endl;
  return 0;
}
