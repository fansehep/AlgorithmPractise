#include "leetcode.hpp"

class Solution {
 public:
  bool verifyPostorder(vector<int>& postorder) {
    return verifyOrder(postorder, 0, postorder.size() - 1);
  }

  bool verifyOrder(vector<int>& postorder, int l, int r) {

    if (l >= r) {
      return true;
    }

    int i;

    for (i = r; i >= l; i--) {
      if (postorder[i] < postorder[r]) {
        break;
      }
    }

    for (int j = i; j >= l; j--) {
      if (postorder[j] > postorder[r]) {
        return false;
      }
    }

    return verifyOrder(postorder, l, r) && verifyOrder(postorder, i + 1, r - 1);
  }
};