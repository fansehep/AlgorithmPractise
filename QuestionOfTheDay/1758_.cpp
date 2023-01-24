#include "leetcode.hpp"

class Solution {
 public:
  int minOperations(string s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (c != ('0' + i % 2)) {
        cnt++;
      }
    }
    return min(cnt, static_cast<int>(s.size()) - cnt );
  }
};
