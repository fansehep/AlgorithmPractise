#include "leetcode.hpp"

class Solution {
  public:
  int rotateDigits(int n) {
    vector<int> digits;
    while (n) {
      digits.push_back(n % 10);
      n /= 10;
    }
    reverse(digits.begin(), digits.end());

    memset(memo, -1, sizeof(memo));
    function<int(int, bool, bool)> fn = [&](int pos, bool bound,
                                            bool diff) -> int {
      if (pos == digits.size()) {
        return diff;
      }
      if (memo[pos][bound][diff] != -1) {
        return memo[pos][bound][diff];
      }

      int ret;
      for (int i = 0; i < (bound ? digits[pos] : 9); ++i) {
        if (check[i] != -1) {
          ret +=
              fn(pos + 1, bound && (i == digits[pos]), diff || (check[i] == 1));
        }
      }
      return memo[pos][bound][diff] = ret;
    };
    int ans = fn(0, true, false);
    return ans;
  }

  private:
  static constexpr int check[10] = {0, 0, 1, -1, -1, 1, 1, -1, 0, 1};
  int memo[5][2][2];
};
