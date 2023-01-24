#include "leetcode.hpp"

class Solution {
 public:
  unordered_map<int, int> index;

  TreeNode* _buildTree(const vector<int>& preorder, const vector<int>& inorder,
                       int preorder_left, int preorder_right, int inorder_left,
                       int inorder_right) {
    //
    if (preorder_left > preorder_right) {
      return nullptr;
    }
    int preorder_root = preorder_left;
    int inorder_root = index[preorder[preorder_root]];

    auto root = new TreeNode(preorder[preorder_root]);
    int left_subtree_size = inorder_root - inorder_left;
    //
    root->left = _buildTree(preorder, inorder, preorder_left + 1,
                            preorder_left + left_subtree_size, inorder_left,
                            inorder_root);
    //
    root->right =
        _buildTree(preorder, inorder, preorder_left + left_subtree_size + 1,
                   preorder_right, inorder_root + 1, inorder_right);
    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    const int preorder_size = preorder.size();
    int i = 0;
    for (; i < preorder_size; i++) {
      index[inorder[i]] = i;
    }
    return _buildTree(preorder, inorder, 0, preorder_size - 1, 0,
                      preorder_size - 1);
  }
};
