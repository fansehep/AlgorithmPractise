#include "leetcode.hpp"

class Solution {
  public:
    vector<int> res;
    vector<int> levelOrder(TreeNode* root) {
      if (nullptr == root) {
        return res;
      }
      queue<TreeNode*> que;
      que.push(root);
      while (!que.empty()) {
        auto node = que.front();
        res.push_back(node->val);
        que.pop();
        if (node->left) {
          que.push(node->left);
        }
        if (node->right) {
          que.push(node->right);
        }
      }
      return res;
    }
};

