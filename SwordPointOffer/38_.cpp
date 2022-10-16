#include "leetcode.hpp"

class Solution {
 public:
  bool nextPermutation(string& str) {
    int i = str.size() - 2;

    //
    while (i >= 0 && str[i] >= str[i + 1]) {
      i--;
    }
    if (i < 0) {
      return false;
    }
    int j = str.size() - 1;
    while (j >= 0 && str[i] >= str[j]) {
      j--;
    }
    swap(str[i], str[j]);
    reverse(str.begin() + i + 1, str.end());
    return true;
  }
// s = "abc"
// nextPermutation: 1.
//  i = 3 - 2 = 1;
//  
  vector<string> permutation(string s) {
    vector<string> res;
    sort(res.begin(), res.end());
    
    do {
      res.push_back(s);
    } while (nextPermutation(s));
    return res;
  }
};
