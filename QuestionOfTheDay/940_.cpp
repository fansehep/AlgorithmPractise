#include "leetcode.hpp"



class Solution {
public:
  static constexpr int mod = 1000000007;
  int distinctSubseqII(string s) {
    vector<int> last(26, -1);
    int n = s.size();
    vector<int> f(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 26; ++j) {
        if (last[j] != -1) {
          f[i] = (f[i] + f[last[j]]) % mod;
        }
      }
    }
  }
};
