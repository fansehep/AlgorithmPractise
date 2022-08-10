#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int divide(int a, int b) {
    if (a == INT_MIN) {
      return INT_MIN;
    }
    if (b == -1) {
      return INT_MAX;
    }
    if (b == INT_MIN) {
      return a == INT_MIN ? 1 : 0;
    }
    if (a == 0) {
      return 0;
    }
    bool rev = false;
    if (a > 0) {
      a = -a;
      rev = !rev;
    }
  }
};