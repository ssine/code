#include "leetcode.h"
#include "utils.h"

using ListNode = ListNodeT<int>;

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* target = new ListNode(0);
    auto tmp = target;
    while (true) {
      int min_val = numeric_limits<int>::max();
      int min_idx = -1;
      for (int idx = 0; idx < lists.size(); idx++) {
        auto l = lists[idx];
        if (l && l->val < min_val) {
          min_idx = idx;
          min_val = l->val;
        }
      }
      if (min_idx == -1) break;
      auto& min_node = lists[min_idx];
      tmp->next = new ListNode(min_node->val);
      min_node = min_node->next;
      tmp = tmp->next;
    }
    return target->next;
  }
};

int main() {
  Solution sol;
  vector<ListNode*> t = {create_list({1, 4, 5}), create_list({1, 3, 4}), create_list({2, 6})};
  print_list(sol.mergeKLists(t));
  // print_list(sol.mergeKLists({create_list({}), create_list({1, 3, 4})}));
  // print_list(sol.mergeKLists({create_list({}), create_list({})}));
  return 0;
}
