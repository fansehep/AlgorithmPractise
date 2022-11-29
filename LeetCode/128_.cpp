#include <bits/stdc++.h>
#include <limits>
using namespace std;
static constexpr int N = 100000;

int vec_num[N] = {0};

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    // 数组没有数据, 直接返回
    if (nums.size() == 0) {
      return 0;
    }
    //
    //
    std::unordered_map<int, bool> vec_map;
    for (auto& iter : nums) {
      vec_map[iter] = true;
    }
    int res = numeric_limits<int>::min();
    for (auto& iter : vec_map) {
      if (false == vec_map[iter.first - 1]) {
        auto flag = iter.first;
        auto current_length = 1;
        while (true) {
          if (true == vec_map[(flag + 1)]) {
            flag ++;
            current_length++;
          } else {
            break;
          }
        }
        res = max(res, current_length);
      }
    }
    return res;
  }
};

int main() {
  std::vector<int> test = {1, 2, 3, 4, 5, 6, 7, 8, 0};
  std::cout << Solution().longestConsecutive(test);
  return 0;
}