#include "leetcode.h"
#include "utils.h"

using ListNode = ListNodeT<int>;

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* a = head;
    ListNode* b = head->next;
    ListNode* h = b;
    ListNode* c;
    while (true) {
      c = b->next;
      b->next = a;
      a->next = c;
      if (!c || !c->next) break;
      a->next = c->next;
      a = c;
      b = a->next;
    }
    return h;
  }
};

int main() {
  Solution sol;
  print_list(sol.swapPairs(create_list({})));
  print_list(sol.swapPairs(create_list({1})));
  print_list(sol.swapPairs(create_list({1, 2})));
  print_list(sol.swapPairs(create_list({1, 2, 3, 4, 5, 6})));
  print_list(sol.swapPairs(create_list({1, 2, 3, 4, 5, 6, 7})));
  return 0;
}
