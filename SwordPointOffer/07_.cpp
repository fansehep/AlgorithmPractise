#include "leetcode.h"
class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (!preorder.size()) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[0]);
    stack<TreeNode*> stk;
    int inorderindex = 0;
    const auto presize = preorder.size();
    for (auto i = 0; i < presize; ++i) {
      int preorderval = preorder[i];
      TreeNode* node = stk.top();
    }
  }
};