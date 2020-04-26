#include "leetcode.h"
#include "utils.h"

using ListNode = ListNodeT<int>;

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* target = new ListNode(0);
    auto tmp = target;
    while (true) {
      if (!l1) {
        tmp->next = l2;
        break;
      }
      if (!l2) {
        tmp->next = l1;
        break;
      }
      if (l1->val < l2->val) {
        tmp->next = new ListNode(l1->val);
        l1 = l1->next;
      } else {
        tmp->next = new ListNode(l2->val);
        l2 = l2->next;
      }
      tmp = tmp->next;
    }
    return target->next;
  }
};

int main() {
  Solution sol;
  print_list(sol.mergeTwoLists(create_list({1, 2, 4}), create_list({1, 3, 4})));
  print_list(sol.mergeTwoLists(create_list({}), create_list({1, 3, 4})));
  print_list(sol.mergeTwoLists(create_list({}), create_list({})));
  return 0;
}
