#include "leetcode.h"
#include "utils.h"

using ListNode = ListNodeT<int>;

class Solution {
 public:
  bool has_k_remain(ListNode* h, int k) {
    ListNode* tmp = h;
    for (int i = 0; i < k; i++) {
      if (!tmp)
        return false;
      tmp = tmp->next;
    }
    return true;
  }
  auto reverse_k(ListNode* head, int k) {
    ListNode* h = head;
    ListNode* a = head;
    ListNode* b = a->next;
    ListNode* t;
    for (int i = 0; i < k - 1; i++) {
      t = b->next;
      b->next = a;
      a = b;
      b = t;
    }
    h->next = b;
    return make_pair(a, h);
  }
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* h = head;
    ListNode* first;
    ListNode* last;
    ListNode* prev_last;
    bool is_first_run = true;
    while (true) {
      if (!has_k_remain(h, k)) {
        return head;
      }
      tie(first, last) = reverse_k(h, k);
      if (is_first_run) {
        is_first_run = false;
        head = first;
      } else {
        prev_last->next = first;
      }
      h = last->next;
      prev_last = last;
    }
    return head;
  }
};

int main() {
  Solution sol;
  print_list(sol.reverseKGroup(create_list({}), 2));
  print_list(sol.reverseKGroup(create_list({1, 2, 3, 4, 5}), 2));
  print_list(sol.reverseKGroup(create_list({1, 2, 3, 4, 5}), 3));
  return 0;
}
