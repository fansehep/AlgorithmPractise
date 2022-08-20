#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> exchange(vector<int>& nums) {
    const auto size = nums.size();
    int l = 0;
    int r = size - 1;
    while (l < r) {
      while (l < r && (nums[l] & 1)) {
        l++;
      }
      while (l < r && !(nums[r] & 1)) {
        r--;
      }
      swap(nums[l], nums[r]);
    }
    return nums;
  }
};

int main () {
  cout << (1 & 1) << " " << (2 & 1) << endl;
  vector<int> a = {1, 2, 3, 4};
  Solution().exchange(a);
  return 0;
}