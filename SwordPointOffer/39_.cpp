#include "leetcode.hpp"

class Solution {
public:
  vector<string> rec;
  vector<int> vis;
  void backtrack(const string& s, int i, int n, string& perm) {

  }
  vector<string> permutation(string s) {
    int n = s.size();
    vis.resize(n);
    sort(s.begin(), s.end());
    string perm;
    backtrack(s, 0, n, perm);
    return rec;
  }
};