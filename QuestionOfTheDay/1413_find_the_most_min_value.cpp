#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minStartValue(vector<int>& nums) {
      if (*min_element(nums.begin(), nums.end()) >= 0) {
          return 1;
      }
      auto sum = 0;
      const auto len = nums.size();
      auto minvalue = 1;
      for (auto i = 0; i < len; i++) {
          sum += nums[i];
          if (sum < 1) {
              if (1-sum > minvalue) {
                  minvalue = 1-sum;
              }
          }
      }
      return minvalue;
    }
};

