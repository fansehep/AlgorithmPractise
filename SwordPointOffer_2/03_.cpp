#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int findRepeatNumber(vector<int> &nums) {
    for (auto &iter : nums) {
      set_.insert(iter);
      if (set_.count(iter) == 2) {
        return iter;
      }
    }
  }
  int findRepeatNumber_2(vector<int> &nums) {
    auto i = 0;
    const auto size = nums.size();
    while (i < size) {
      if (nums[i] == i) {
        i++;
        continue;
      }
      if (nums[nums[i]] == nums[i]) {
        return nums[i];
      }
      swap(nums[nums[i]], nums[i]);
    }
  }
  multiset<int> set_;
};