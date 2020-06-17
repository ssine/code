#include "leetcode.h"

class Solution {
  // return whether a > b, suppose they have equal length
  bool ansCmp(const vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] > b[i])
        return true;
      else if (a[i] < b[i])
        return false;
    }
    return false;
  }

public:
  vector<int> maxNumberSingle(vector<int> &nums, int k) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      while (ans.size() && ans.size() + nums.size() - i > k && ans.back() < nums[i]) {
        ans.pop_back();
      }
      ans.push_back(nums[i]);
    }
    return {ans.begin(), ans.begin() + k};
  }

  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    int size1 = nums1.size(), size2 = nums2.size();
    vector<int> maxNum(k, 0);
    for (int len1 = max(0, k - size2); len1 <= min(k, size1); len1++) {
      int len2 = k - len1;
      auto v1 = maxNumberSingle(nums1, len1);
      auto v2 = maxNumberSingle(nums2, len2);
      vector<int> ans;
      int i1 = 0, i2 = 0;
      while (ans.size() < k) {
        if (i1 >= v1.size())
          ans.push_back(v2[i2++]);
        else if (i2 >= v2.size())
          ans.push_back(v1[i1++]);
        else {
          if (v1[i1] > v2[i2]) {
            ans.push_back(v1[i1++]);
          } else if (v1[i1] < v2[i2]) {
            ans.push_back(v2[i2++]);
          } else {
            int i = 1;
          check:
            if (i1 + i >= v1.size())
              ans.push_back(v2[i2++]);
            else if (i2 + i >= v2.size())
              ans.push_back(v1[i1++]);
            else if (v1[i1 + i] > v2[i2 + i])
              ans.push_back(v1[i1++]);
            else if (v1[i1 + i] < v2[i2 + i])
              ans.push_back(v2[i2++]);
            else {
              i++;
              goto check;
            }
          }
        }
      }
      if (ansCmp(ans, maxNum)) {
        maxNum = ans;
      }
    }
    return maxNum;
  }
};

int main() {
  Solution sol;
  // vector<int> arr1 = {3, 4, 6, 5};
  // vector<int> arr2 = {9, 1, 2, 5, 8, 3};
  // print_vector(sol.maxNumber(arr1, arr2, 5));
  // vector<int> arr1 = {6, 7};
  // vector<int> arr2 = {6, 0, 4};
  // print_vector(sol.maxNumber(arr1, arr2, 5));
  vector<int> arr1 = {3, 9};
  vector<int> arr2 = {8, 9};
  print_vector(sol.maxNumber(arr1, arr2, 3));
  return 0;
}
