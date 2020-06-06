#include "leetcode.h"
#include "utils.h"

using TreeNode = TreeNodeT<int>;

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (!root) return {};
    vector<int> ans;
    // pair of tree node and if this node need further traverse
    stack<pair<TreeNode *, bool>> st;
    st.push(make_pair(root, true));
    while (!st.empty()) {
      TreeNode *node;
      bool needTraverse;
      tie(node, needTraverse) = st.top();
      st.pop();
      if (needTraverse) {
        st.push(make_pair(node, false));
        if (node->right)
          st.push(make_pair(node->right, true));
        if (node->left)
          st.push(make_pair(node->left, true));
      } else {
        ans.push_back(node->val);
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  print_vector(sol.postorderTraversal(construct_tree<int>({1, 1, 2, 3}, {false, true, false, false})));
  return 0;
}
