#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string solveEquation(string equation) {
    if (equation == "x=x") {
        return "Infinite solutions";
    }
    vector<int> operatornums;
    const auto equation_size = equation.length();
    //* x 的出现的次数
    auto x_n = 0;
    bool isleft = false;
    for (auto i = 0; i < equation_size; i++) {
      //* 如果是 x 那么就跳过
      //* '+', 后面是数字
      if (equation[i] == 'x') {
        if (!isleft) {
          x_n++;
        } else {
          x_n--;
        }
        continue;
      }
      if (equation[i] == '+') {
        int sum = 0;
        auto j = i + 1;
        for (; j < equation_size; j++) {
          if (equation[j] >= '0' && equation[j] <= '9') {
            sum = sum * 10 + (equation[j] - '0');
          } else {
            break;
          }
        }
        if (equation[j] == 'x') {
          if (sum == 0 && j == i + 1) {
            sum = 1;
          }
          if (!isleft) {
            x_n += sum;
          } else {
            x_n -= sum;
          }
          i = j;
          continue;
        }
        if (!isleft) {
          operatornums.push_back(sum);
        } else {
          operatornums.push_back(-1 * sum);
        }
        i = j;
        i--;
        continue;
      }
      if (equation[i] == '-') {
        int sum = 0;
        auto j = i + 1;
        for (; j < equation_size; j++) {
          if (equation[j] >= '0' && equation[j] <= '9') {
            sum = sum * 10 + (equation[j] - '0');
          } else {
            break;
          }
        }
        if (equation[j] == 'x') {
          if (sum == 0 && j == (i + 1)) {
            sum = 1;
          }
          if (!isleft) {
            x_n -= sum;
          } else {
            x_n += sum;
          }
          i = j;
          continue;
        }
        if (!isleft) {
          operatornums.push_back(-1 * sum);
        } else {
          operatornums.push_back(sum);
        }
        i = j;
        i--;
        continue;
      }
      //* 遇到方程的 '=', 则表示, 符号转换.
      if (equation[i] == '=') {
        isleft = true;
        continue;
      }
      //* 遇到数字
      if (equation[i] >= '0' && equation[i] <= '9') {
        int sum = equation[i] - '0';
        auto j = i + 1;
        for (; j < equation_size; j++) {
          if (equation[j] >= '0' && equation[j] <= '9') {
            sum = sum * 10 + (equation[j] - '0');
          } else {
            break;
          }
        }
        if (equation[j] == 'x') {
          if (!isleft) {
            x_n += sum;
          } else {
            x_n -= sum;
          }
          i = j;
          continue;
        }
        if (!isleft) {
          operatornums.push_back(sum);
        } else {
          operatornums.push_back(-1 * sum);
        }
        i = j;
        i--;
        continue;
      }
    }
    auto sum = 0;
    for (auto &iter : operatornums) {
      sum += iter;
    }
    for_each(operatornums.begin(), operatornums.end(),
              [](int val) { printf("%d ", val); });
    printf("\n%d\n", x_n);
    if (x_n == 0 && sum != 0) {
        return "No solution";
    }
    if (x_n == 0 && sum == 0) {
      return "Infinite solutions";
    }
    char buf[128];
    snprintf(buf, sizeof(buf), "x=%d", -(sum / x_n));
    return string(buf);
  }
};
// 32 1159
// 64 2599
int main() {
  std::cout << Solution().solveEquation("0x+0x=0x");

  return 0;
}