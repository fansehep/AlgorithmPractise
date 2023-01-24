#include <limits>

#include "leetcode.hpp"

class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int64_t min_v = numeric_limits<int64_t>::max();
    const int N = points.size();
    int i = 0;
    int res = -1;
    for (; i < N; i++) {
      // 有效
      if ((points[i][0] == x || points[i][1] == y)) {
        //
        auto new_min_v = ::abs(points[i][0] - x) + ::abs(points[i][1] - x);
        if (new_min_v < min_v) {
            min_v = new_min_v;
            res = i;
        }
      }
    }
    return res;
  }
};


int main () {
  
  return 0;
}