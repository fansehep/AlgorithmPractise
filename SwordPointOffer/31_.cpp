#include "leetcode.hpp"

class Solution {
public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int i = 0;
    int j = 0;
    for (auto& iter : pushed) {
      pushed[i] = iter;
      while (i >= 0 && pushed[i] == popped[j]) {
        ++i;
        j--;
      }
      ++i;
    }
    return i == 0;
  }
};
