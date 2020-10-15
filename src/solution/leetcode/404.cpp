#include "leetcode.h"

using TreeNode = TreeNodeT<int>;

class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root)
      return 0;

    int sum = 0;

    function<void(TreeNode *, bool)> dfs = [&](TreeNode *node, bool isLeft) {
      if (isLeft && !node->left && !node->right)
        sum += node->val;
      if (node->left)
        dfs(node->left, true);
      if (node->right)
        dfs(node->right, false);
    };

    dfs(root, false);

    return sum;
  }
};

int main() {
  auto *root = construct_tree<int>({1, 2, 3, 4, 5}, {false, false, false, false, false});
  Solution sol;
  cout << sol.sumOfLeftLeaves(root) << endl;
  return 0;
}
