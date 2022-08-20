#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
  vector<int> nums;
  string str;
public:
  vector<int> PrintNumbers(int n) {
    str.resize(n, '0');
    DFS(n, 0);
  }
  void DFS(int end, int index) {
    if (index == end) {
      Save();
      return;
    }
    for (auto i = 0; i <= 9; ++i) {
      str[index] = i + '0';
      DFS(end, index + 1);
    }
  }

  void Save() {
    int ptr = 0;
    while (ptr < str.size() && str[ptr] == '0') {
      ptr++;
    }
    if (ptr != str.size()) {
      nums.emplace_back(stoi(str.substr(ptr)));
    }
  }
};
