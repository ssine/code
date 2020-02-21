/**
 * http://acm.hdu.edu.cn/game/entry/problem/show.php?chapterid=1&sectionid=3&problemid=16
 */
#include <iostream>
#include <vector>
#include <algorithm>
// #include "utils.h"

using namespace std;

struct stick {
  int l, w;
};

int main () {
  // redirect_in_to_file(cin, "D:\\Projects\\code\\src\\solution\\hdu\\in");
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    vector<stick> pile;
    for (int i = 0; i < n; i++) {
      stick s;
      cin >> s.l >> s.w;
      pile.emplace_back(s);
    }

    sort(pile.begin(), pile.end(), [](stick a, stick b) {
      return a.l == b.l ? a.w < b.w : a.l < b.l;
    });

    vector<stick> groups;
    for (auto it : pile) {
      bool fit = false;
      for (auto& p : groups) {
        if (it.l >= p.l && it.w >= p.w) {
          p = it;
          fit = true;
          break;
        }
      }
      if (!fit) groups.push_back(it);
    }
    cout << groups.size() << endl;
  }
  return 0;
}
