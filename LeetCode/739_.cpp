#include "leetcode.hpp"

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    const auto vec_size = temperatures.size();
    vector<int> result(vec_size, 0);
    stack<int> stk;
    uint32_t i = 0;
    for (; i < vec_size; i++) {
      while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
        auto pre_idx = stk.top();
        result[pre_idx] = i - pre_idx;
        stk.pop();
      }
      result.push_back(i);
    }
    return result;
  }
};
