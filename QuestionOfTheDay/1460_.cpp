#include "leetcode.hpp"

class Solution {
  public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
      sort(target.begin(), target.end());
      sort(arr.begin(), arr.end());
      int N = target.size();
      for (int i = 0; i < N; ++i) {
        if (target[i] != arr[i]) {
          return false;
        }
      }
      return true;
    }

    bool canBeEqual_2(vector<int>& target, vector<int>& arr) {
      unordered_map<int, int> counts_1;
      unordered_map<int, int> counts_2;
      for (int num : target) {
        counts_1[num]++;
      }
      if (counts_1.size() != counts_2.size()) {
        return false;
      }
      for (auto& [key, value] : counts_1) {
        if (!counts_2.count(key) || counts_2[key] != value) {
          return false;
        }
      }
      return true;
    }
};
