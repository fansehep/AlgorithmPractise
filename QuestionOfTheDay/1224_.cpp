#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxEqualFreq(const vector<int>& nums) {
    const int size = nums.size();
    int res = 0;
    int maxfreq = 0;
    for (int i = 0; i < size; i++) {
      if (count[nums[i]] > 0) {
        freq[count[nums[i]]]--;
      }
      count[nums[i]]++;
      maxfreq = max(maxfreq, count[nums[i]]);
      freq[count[nums[i]]]++;
    }
  }
  // value -> 出现次数
  unordered_map<int, int> freq;
  unordered_map<int, int> count;
};


int main () {
  std::cout << Solution().maxEqualFreq({2, 2, 1, 1, 5, 3, 3, 5});



  return 0;
}