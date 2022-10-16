#include "leetcode.hpp"

class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    int i = 0;
    int j = 0;
    const int s1_size = s1.size();
    int s2_size = s2.size() - 1;
    int mul_idx_1 = -1;
    int mul_idx_2 = s2_size;
    for (; i < s1_size; ++i) {
      if (s1[i] != s2[i]) {
        mul_idx_1 = i;
        break;
      }
    }
    if (mul_idx_1 == -1) {
      return true;
    }
    for (; s2_size >= 0; s2_size--) {
      if (s1[s2_size] != s2[s2_size]) {
        mul_idx_2 = s2_size;
        break;
      }
    }
    for (j = mul_idx_1; j < mul_idx_2; j++) {
      if (s1[j] != s2[j]) {
        return false;
      }
    }
    if (s1[mul_idx_1] == s2[mul_idx_2]) {
      return true;
    }
    return false;
  }
};

auto main () -> int {
  cout << Solution().areAlmostEqual("abcd", "dcba");

  return 0;
}