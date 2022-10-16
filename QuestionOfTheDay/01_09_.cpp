#include <type_traits>
#include "leetcode.hpp"

class Solution {
  public:
  bool isFlipedString(string s1, string s2) {
    const int s1_len = s1.length();
    const int s2_len = s2.length();
    if (s1_len != s2_len) {
      return false;
    } else if (s1_len == 0 && s2_len == 0) {
      return true;
    }
    int i = 0;
    int j = 0;
    int k = 0;
    //* 暴力的遍历
    //* 假设二者相等, 那么 s1 相当于 s2 轮转 i 个位置
    for (i = 0; i < s1_len; i++) {
      bool flag = true;
      //* 如果在轮转一次之后, 还相等, 即可返回就行
      for (j = 0; j < s2_len; j++) {
        if (s1[(i + j) % s1_len] != s2[j]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        return true;
      }
    }
    return false;
  }

  bool isFlipedString_2(string s1, string s2) {
    return s1.length() == s2.length() && (s1 + s1).find(s2) != string::npos;
  }
};