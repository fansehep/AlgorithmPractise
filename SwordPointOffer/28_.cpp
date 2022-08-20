#include "leetcode.hpp"
class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    return check(root, root);
  }

  bool check(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    }
    if (!p || !q) {
      return false;
    }
    return p->val == q->val &&
      check(p->left, q->right) &&
      check(p->right, q->left);
  }

  bool check_2(TreeNode* u, TreeNode* v) {
    queue<TreeNode*> que;
    que.push(u);
    que.push(v);
    while (!que.empty()) {
      u = que.front();
      que.pop();
      v = que.front();
      que.pop();
      if (!u && !v) {
        continue;
      }
      if ((!u || !v) || (u->val != v->val)) {
        return false;
      }
      que.push(u->left);
      que.push(v->right);

      que.push(u->right);
      que.push(v->left);
    }
    return true;
  }
};
