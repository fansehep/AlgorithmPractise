#include <limits>
#include "leetcode.hpp"

class Solution {
 public:
  unordered_map<int, int> map1_;
  int majorityElement(vector<int>& nums) {
    if (nums.size() == 1 || nums.size() == 2) {
        return nums[0];
    }
    int max = 0;
    int res = 0;
    for (auto& iter : nums) {
      map1_[iter]++;
      if (map1_[iter] > res) {
        res = map1_[iter];
        max = iter;
      }
    }
    return max;
  }
};


int main() {
  vector<int64_t> vec = {1, 2, 3, 2, 2, 2, 5, 4, 2};
  cout << Solution().majorityElement(vec);
  return 0;
}