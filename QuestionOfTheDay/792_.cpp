#include "leetcode.hpp"


class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
      int res = 0;
      const int origin_size = s.size();
      //
      for (auto& t_str : words) {
        const int t_str_size = t_str.size();
        //
        if (t_str_size > origin_size) {
          continue;
        }
        int i = 0;
        int j = 0;
        //
        for (; i < t_str_size && j < origin_size; i++) {
          if (t_str[i] == s[j]) {
            continue;
          } else {
            i--;
          }
          j++;
        }
        //
        if (j == origin_size && i != t_str_size) {
          res++;
        }
      }
      return res;
    }
};
