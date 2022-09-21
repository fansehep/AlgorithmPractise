#ifndef LEETCODE_H_
#define LEETCODE_H_
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, Treenode* right) : val(x), left(left), right(right) {}
}; 

#endif
