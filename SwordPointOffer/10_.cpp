#include "leetcode.h"

class Solution {
 public:
  const static uint64_t MOD = 1000000007;
  int numWays(int n) {
    if (n < 2) {
      return n == 0 ? 1 : n;
    }
    //* DP nums[i] = nums[i-1] + nums[i -2]
    //* 小青蛙每次只能跳一个台阶或者2 个台阶
    //* 那么就是说在任意一个 n (n > 2) 的台阶, 
    //* 它的结果都是由 nums[n -1] nums[n -2] 两个结果相加
    //* 那么这就是动态规划方程
    int a = 1;
    int b = 2;
    for (auto i = 3; i <= n; i++) {
      int t = a + b;
      a = b;
      b = t % MOD;
    }
    return b;
  }
};

