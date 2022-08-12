#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<vector<int>> groupThePeople(const vector<int> &groupSizes) {
    vector<vector<int>> res;
    // index - > size
    vector<pair<int, int>> nums;
    const auto size = groupSizes.size();
    for (auto i = 0; i < size; i++) {
      nums.push_back({i, groupSizes[i]});
    }
    sort(nums.begin(), nums.end(), [](pair<int, int> &a, pair<int, int> &b) {
      return a.second < b.second;
    });
    for (auto i = 0; i < size; i++) {
      vector<int> tmp;
      tmp.resize(0);
      auto t_size = nums[i].second;
      for (auto j = 0; j < t_size; j++) {
        tmp.push_back(nums[i + j].first);
      }
      const auto n_size = tmp.size();
      for (auto i = 0; i < n_size; i++) {
        cout << tmp[i] << endl;
      }
      i += t_size;
      i -= 1;
      res.push_back(tmp);
    }
    return res;
  }
  vector<vector<int>> groupThePeople_2(vector<int>& groupSizes) {
    unordered_map<int, vector<int>> groups;
    const auto size = groupSizes.size();
    for (auto i = 0; i < size; i++) {
      groups[groupSizes[i]].push_back(i);
    }
    vector<vector<int>> res;
    for (auto& iter : groups) {
      res.push_back(iter);
    }
  }
};

int main () {
  auto res = Solution().groupThePeople({1, 3, 3, 3, 3, 3, 3});
  const auto size = res.size();
  for (auto i = 0; i < size; i++) {
    const auto t_size = res[i].size();
    for (auto j = 0; j < t_size; j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}