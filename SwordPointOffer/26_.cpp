#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    bool isSubStructure(TreeNode* A, TreeNode* B) {
      if (A == nullptr || B == nullptr) {
        return false;
      }
      if (A->val == B->val) {
        if (iscontain(A, B)) {
          return true;
        }
      }
      return iscontain(A->left, B) || iscontain(A->right, B);
    }

    bool iscontain(TreeNode* A, TreeNode* B) {
      if (B == nullptr) {
        return true;
      }
      if (A == nullptr || A->val != B->val) {
        return false;
      }
      return iscontain(A->left, B->left) && iscontain(A->right, B->right);
    }

};