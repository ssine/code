#include "leetcode.h"

using TreeNode = TreeNodeT<int>;

class Solution {
public:
  int pathSum(TreeNode *root, int sum) {
    if (!root)
      return 0;

    int count = 0;
    function<void(TreeNode *, vector<int>)> dfs = [&](TreeNode *node, vector<int> prefix) {
      for (int i = 0; i < prefix.size(); i++)
        prefix[i] += node->val;
      prefix.push_back(node->val);

      for (int v : prefix)
        if (v == sum)
          count++;

      if (node->left)
        dfs(node->left, prefix);
      if (node->right)
        dfs(node->right, prefix);
    };
    dfs(root, {});
    return count;
  }
};

int main() {
  Solution sol;
  cout << sol.pathSum(deserialize_tree<int>("10,5,-3,3,2,null,11,3,-2,null,1"), 8) << endl;
  return 0;
}
