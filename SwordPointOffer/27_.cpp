#include "leetcode.hpp"
#include <boost/core/noncopyable.hpp>
using namespace std;
class Solution {
public:
  TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }
    TreeNode* left = mirrorTree(root->left);
    TreeNode* right = mirrorTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
  TreeNode* mirrorTree_2(TreeNode* root) {
    if (!root) {
      return root;
    }
    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
      TreeNode* node = stk.top();
      stk.pop();
      if (node->left) {
        stk.push(node->left);
      }
      if (node->right) {
        stk.push(node->right);
      }
      swap(node->left, node->right);
    }
    return root;
  }
};
