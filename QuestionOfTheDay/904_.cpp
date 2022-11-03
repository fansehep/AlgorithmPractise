#include "leetcode.hpp"

class Solution {
 public:
  // 遍历 fruits, 不断将 cnt[fruits[right]]++;
  // 
  int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    unordered_map<int, int> cnt;
    int left = 0;
    int ans = 0;
    //
    for (int right = 0; right < n; ++right) {
      //
      ++cnt[fruits[right]];
      //
      while (cnt.size() > 2) {
        //
        auto it = cnt.find(fruits[left]);

        --it->second;
        
        if (it->second == 0) {
          cnt.erase(it);
        }
        
        ++left;
      }

      ans = max(ans, right - left + 1);
    }

    return ans;
  }
};
