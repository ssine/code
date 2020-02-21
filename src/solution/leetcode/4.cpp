#include "leetcode.h"

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // ------ l1r | r1l --------
    // ------ l2r | r2l --------
    size_t size1 = nums1.size(), size2 = nums2.size();
    if (size1 > size2) return findMedianSortedArrays(nums2, nums1);

    size_t l = 0, r = size1;
    while (l <= r) {
      size_t p1 = (r + l) / 2;
      size_t p2 = (size1 + size2 + 1) / 2 - p1;

      int l1r = p1 == 0 ? numeric_limits<int>::min() : nums1[p1 - 1];
      int l2r = p2 == 0 ? numeric_limits<int>::min() : nums2[p2 - 1];

      int r1l = p1 == size1 ? numeric_limits<int>::max() : nums1[p1];
      int r2l = p2 == size2 ? numeric_limits<int>::max() : nums2[p2];

      if (l1r <= r2l && l2r <= r1l) {
        if ((size1 + size2) % 2 == 0) {
          return (max(l1r, l2r) + min(r1l, r2l)) * 1.0 / 2;
        } else {
          return max(l1r, l2r);
        }
      } else if (r1l < l2r) {
        l = p1 + 1;
      } else {
        r = p1 - 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;
  vector<int> v1 = {1, 3};
  vector<int> v2 = {2,4,5,6,7,8,9,10};
  cout << sol.findMedianSortedArrays(v1, v2);
  return 0;
}
