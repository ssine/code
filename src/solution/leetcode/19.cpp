#include "leetcode.h"
#include "utils.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto pioneer = head, target = head;
    for (int i = 0; i < n; i++) pioneer = pioneer->next;
    if (!pioneer) { return head->next; }
    while (pioneer->next) {
      pioneer = pioneer->next;
      target = target->next;
    }
    target->next = target->next->next;
    return head;
  }
};

int main() {
  return 0;
}
