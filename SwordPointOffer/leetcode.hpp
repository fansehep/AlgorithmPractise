#ifndef LEETCODE_H_
#define LEETCODE_H_
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x) {}
}; 

struct Node {
  int val;
  Node* next;
  Node* random;
  Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};


#endif