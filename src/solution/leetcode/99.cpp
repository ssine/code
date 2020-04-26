#include "leetcode.h"
#include "utils.h"

using TreeNode = TreeNodeT<int>;

class Solution {
 public:
  void recoverTree(TreeNode* root) {
    TreeNode* last = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    auto dfs = [&](auto&& self, TreeNode* cur) {
      if (!cur)
        return;
      self(self, cur->left);
      if (last && last->val > cur->val) {
        if (first) {
          // second reversed pair
          second = cur;
        } else {
          // first reversed pair
          first = last;
          second = cur;
        }
      }
      last = cur;
      self(self, cur->right);
    };
    dfs(dfs, root);
    swap(first->val, second->val);
  }
};

int main() {
  Solution sol;
  auto root =
      construct_tree<int>({1, 3, 1, 1, 2}, {false, false, true, true, false});
  root =
      construct_tree<int>({3, 1, 4, 1, 1, 2}, {false, false, false, true, true, false});
  sol.recoverTree(root);
  print_binary_tree_inorder(root);
  return 0;
}
