#include "leetcode.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int step = 0, s = 0;
    ListNode* rhead = new ListNode(0);
    ListNode* res = rhead;
    while (l1 || l2) {
      res->next = new ListNode(0);
      res = res->next;
      s = step;
      if (l1) {
        s += l1->val; l1 = l1->next;
      }
      if (l2) {
        s += l2->val; l2 = l2->next;
      }
      step = s / 10;
      s %= 10;
      res->val = s;
    }
    if (step != 0) {
      res->next = new ListNode(step);
    }
    return rhead->next;
  }
};
