#include "leetcode.hpp"

class Solution {
 public:
  const std::string Push = "Push";
  const std::string Pop = "Pop";
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> result;
    result.reserve(target.back());
    const int target_size = target.size();
    int i = 1;
    if (target[0] != 1) {
      int k = 1;
      for (; k < target[0]; ++k) {
        result.emplace_back(Push);
        result.emplace_back(Pop);
      }
    } else {
      result.emplace_back(Push);
    }
    int ttt = 2;
    for (; i < target_size; ++i) {
      if (target[i] == ttt) {
        result.emplace_back(Push);
        ttt++;
        continue;
      } else {
        int size = target[i] - target[i - 1];

        int j = 1;
        for (; j < size; ++j) {
          result.emplace_back(Push);
          result.emplace_back(Pop);
        }
        result.emplace_back(Push);
        ttt = target[i] + 1;
      }
    }
    return result;
  }
};
