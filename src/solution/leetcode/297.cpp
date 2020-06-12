#include "leetcode.h"
#include "utils.h"

using TreeNode = TreeNodeT<int>;

class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    vector<string> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      if (t == NULL) {
        ans.push_back("null");
      } else {
        ans.push_back(to_string(t->val));
        q.push(t->left);
        q.push(t->right);
      }
    }
    stringstream ss;
    ss << ans[0];
    for (size_t i = 1; i < ans.size(); i++) {
      ss << ',' << ans[i];
    }
    return ss.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    auto nodes = split_string(data, ",");
    size_t idx = 0;
    queue<TreeNode **> q;
    TreeNode *root = NULL;
    q.push(&root);
    for (auto &nd : nodes) {
      TreeNode **t = q.front();
      q.pop();
      if (nd[0] != 'n') {
        int v;
        from_chars(nd.data(), nd.data() + nd.size(), v);
        *t = new TreeNode(v);
        q.push(&(*t)->left);
        q.push(&(*t)->right);
      }
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
  Codec sol;
  // print_binary_tree_bfs(sol.deserialize(
      // sol.serialize(construct_tree<int>({1, 2, 3, 3, 3, 4, 5}, {false, false, false, true, true, false, false}))));
  // auto rt = sol.deserialize("1,2,3,null,null,4,5");
  cout << serialize_tree(deserialize_tree<int>("1,2,3,null,null,4,5")) << endl;
  return 0;
}
