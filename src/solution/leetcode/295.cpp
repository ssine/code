#include "leetcode.h"

class MedianFinder {
  // left set & right set, rs is larger when total num is odd
  multiset<int> ls, rs;

public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (rs.size() == 0) {
      rs.insert(num);
      return;
    }
    if (num < *rs.begin()) {
      ls.insert(num);
      if (ls.size() > rs.size()) {
        rs.insert(*ls.rbegin());
        ls.erase(--ls.end());
      }
    } else {
      rs.insert(num);
      if (rs.size() > ls.size() + 1) {
        ls.insert(*rs.begin());
        rs.erase(rs.begin());
      }
    }
  }

  double findMedian() {
    if (rs.size() == 0)
      return 0.0;
    if (rs.size() > ls.size()) {
      return *rs.begin();
    } else {
      return (*ls.rbegin() + *rs.begin()) / 2.0;
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
  MedianFinder finder;
  cout << finder.findMedian() << endl;
  finder.addNum(1);
  cout << finder.findMedian() << endl;
  finder.addNum(2);
  cout << finder.findMedian() << endl;
  finder.addNum(3);
  cout << finder.findMedian() << endl;
  return 0;
}
