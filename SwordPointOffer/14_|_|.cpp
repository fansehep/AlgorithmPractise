#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int cuttingRope(int n) {
    if (n <= 3) {
      return n - 1;
    }
    int b = n % 3;
    int mod = 1000000007;
    long long ret = 1;
    int linenums = n / 3;
    for (int i = 1; i < linenums; i++) {
      ret = 3 * ret % mod;
    }
    if (b == 0) {
      return (int)(ret * 3 % mod);
    }
    if (b == 1) {
      return int(ret * 4 % mod);
    }
    return (int)(ret * 6 % mod);
  }
};