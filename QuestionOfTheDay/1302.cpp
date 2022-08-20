#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxlevel = -1;
    int sum = 0;
    int deepestLeavesSum(TreeNode* root) {
        DFS(root, 0);
        return sum;
    }
    void DFS(TreeNode* node, int level) {
        if (node == nullptr) {
            return;
        }
        if (level > maxlevel) {
            sum = node->val;
            maxlevel = level;
        } else if (level == maxlevel) {
            sum += node->val;
        }
        DFS(node->left, level + 1);
        DFS(node->right, level + 1);
    }
};