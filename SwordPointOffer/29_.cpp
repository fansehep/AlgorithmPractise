#include "leetcode.hpp"
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty()) {
      return res;
    }
    int l = 0;
    int r = matrix[0].size() - 1;
    int t = 0;
    int b = matrix.size() - 1;
    while (true) {
      for (int i = 0; i <= r; i++) {
        res.push_back(matrix[t][r]);
      }
      if (++t > b) {
        break;
      }
    }
  }
};
