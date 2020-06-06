#include "leetcode.h"
#include "utils.h"

class Solution {
public:
  int candy(vector<int> &ratings) {
    size_t n = ratings.size();
    vector<int> numCandy(n, 0);
    // greater than left
    vector<bool> gtl(n);
    // greater than right
    vector<bool> gtr(n);
    for (int i = 0; i < n; i++) {
      gtl[i] = i != 0 && ratings[i - 1] < ratings[i];
      gtr[i] = i != n - 1 && ratings[i] > ratings[i + 1];
      if (!gtl[i] && !gtr[i]) {
        // a miserable nadir gets only 1 candy
        numCandy[i] = 1;
        // goes back to fill the candies
        for (int j = i - 1; j >= 0; j--) {
          if (gtr[j]) {
            numCandy[j] = max(numCandy[j], numCandy[j+1] + 1);
          } else {
            break;
          }
        }
      } else if (gtl[i]) {
        numCandy[i] = numCandy[i-1] + 1;
      }
    }
    return accumulate(numCandy.begin(), numCandy.end(), 0);
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1, 2, 2};
  cout << sol.candy(arr) << endl;
  return 0;
}
