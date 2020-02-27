#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
#include <inttypes.h>
#include <cmath>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list(vector<int> nums) {
  ListNode* head = new ListNode(0);
  auto tmp = head;
  for (int& n : nums) {
    tmp->next = new ListNode(n);
    tmp = tmp->next;
  }
  return head->next;
}

void print_list(ListNode* head) {
  auto tmp = head;
  while (tmp) {
    cout << tmp->val;
    if (tmp->next) cout << "->";
    tmp = tmp->next;
  }
  cout << endl;
  return;
}
