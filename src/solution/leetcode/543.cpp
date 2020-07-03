#include "leetcode.h"

using TreeNode = TreeNodeT<int>;

class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;
    int diameter = 0;
    function<int(TreeNode *)> treeHeight = [&](TreeNode *n) {
      int heightLeft = n->left ? treeHeight(n->left) + 1 : 0;
      int heightRight = n->right ? treeHeight(n->right) + 1 : 0;
      diameter = max(diameter, heightLeft + heightRight);
      return max(heightLeft, heightRight);
    };
    treeHeight(root);
    return diameter;
  }
};

int main() {
  Solution sol;
  cout << sol.diameterOfBinaryTree(deserialize_tree<int>("1,2,3,4,5")) << endl;
  return 0;
}
