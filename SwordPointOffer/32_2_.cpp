#include "leetcode.hpp"


class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) noexcept {
      vector<vector<int>> res;
      if (nullptr == root) {
        return res;
      }
      queue<TreeNode*> que;
      que.push(root);
      que.push(nullptr);
      res.push_back({});
      while (!que.empty()) {
        auto node = que.front();
        que.pop();
        if (node) {
          res.back().emplace_back(node->val);
          if (node->left) { 
            que.push(node->left);
          }
          if (node->right) {
            que.push(node->right);
          }
        } else if (!que.empty()) {
          res.push_back({});
          que.push(nullptr);
        }
      }
      return res;
    }
};

