#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxScore(string s) {
    int o_n = 0;
    int one_n = 0;
    int sum = 0;
    const int strsize = s.size();
    int sum_t[strsize] = {0};
    int sum_1_t[strsize] = {0};
    int last_1_index = 0;
    int last_0_index = 0;
    for (auto i = 0; i < strsize; i++) {
      if (s[i] == '0') {
        sum_t[i] = sum_t[last_0_index] + 1;
        last_0_index = i;
      }
      if (s[strsize - i - 1] == '1') {
        sum_1_t[strsize - i - 1] = sum_1_t[last_1_index] + 1;
        last_1_index = strsize - i - 1;
      }
    }
    for (auto i = 0; i < strsize - 1; i++) {
      sum = max(sum, sum_t[i] + sum_1_t[i+1]);
    }
    return sum;
  }
};

int main() {
  std::cout << Solution().maxScore("011101");

  return 0;
}
