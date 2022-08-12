#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  string reformat(const string& s) {
    const auto size = s.length();
    int sum_digit = 0;
    for (auto& chat : s) {
      if (isdigit(chat)) {
        sum_digit++;
      }
    }
    
  }
};

int main () {
  std::cout << Solution().reformat("a0b1c2");

  return 0;
}