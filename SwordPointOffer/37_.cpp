#include <sstream>

#include "leetcode.hpp"

class Codec {
 public:
  string serialize(TreeNode* root) {
    if (root == nullptr) {
      return "";
    }

    ostringstream output;
    queue<TreeNode*> que;
    que.push(root);

    while (!que.empty()) {
      auto node = que.front();
      que.pop();
      if (node == nullptr) {
        output << "# ";
      } else {
        output << node->val << " ";
        que.push(node->left);
        que.push(node->right);
      }
    }
    std::cout << output.str();
    return output.str();
  }

  TreeNode* deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }

    vector<TreeNode*> nodes;

    string val;

    istringstream input(data);

    while (input >> val) {
      if (val == "#") {
        nodes.push_back(nullptr);
      } else {
        nodes.push_back(new TreeNode(stoi(val)));
      }
    }
    int pos = 1;
    int i = 0;
    for (; i < nodes.size(); ++i) {
      if (nodes[i] == nullptr) {
        continue;
      }
      nodes[i]->left = nodes[pos++];
      nodes[i]->right = nodes[pos++];
    }
    return nodes[0];
  }
};