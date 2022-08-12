#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  //
  //   [1,   4,  7, 11, 15],
  //   [2,   5,  8, 12, 19],
  //   [3,   6,  9, 16, 22],
  //   [10, 13, 14, 17, 24],
  //   [18, 21, 23, 26, 30]
  //
  bool findNumberIn2DArray(const vector<vector<int>> &matrix, int target) {
    const auto width = matrix.size();
    if (width == 0) {
      return false;
    }
    const auto length = matrix[0].size();
    if (length == 0) {
      return false;
    }
    if (width == 1 && length == 1) {
      return matrix[0][0] == target;
    } else if (width == 1 && length != 1) {
      return binary_search(matrix[0].begin(), matrix[0].end(), target);
    }
    auto i = length - 1;
    auto j = 0;
    for (; i >= 0 && j < width;) {
      if (matrix[j][i] > target) {
        i--;
      } else if (matrix[i][j] < target) {
        j++;
      } else {
        return true;
      }
    }
    return false;
  }
};
#pragma GCC optimze("Ofast")

/*
 1, 2, 3
 4, 5, 6
*/

int main() {
//   const std::vector<vector<int>> &&test = {{1, 3, 7, 11, 15},
//                                            {2, 5, 8, 12, 19},
//                                            {3, 6, 9, 16, 22},
//                                            {10, 13, 14, 17, 24},
//                                            {18, 21, 23, 36, 30}};
//   const std::vector<vector<int>> &&test_2 = {{-1}, {-1}};
//  std::cout << Solution().findNumberIn2DArray(test_2, -2);
  vector<int> a = {1, 2, 3};
  sort(a.begin(), a.end(), [](int a, int b){ return a > b;});
  for (const auto& iter : a) {
    cout << iter << endl;
  }
  return 0;
}
