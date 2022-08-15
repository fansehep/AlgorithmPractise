#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceSpace(string& s) {
      for (auto i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
          s[i] = '%';
          s.insert(i+1, "20");
        }
      }
      return s;
    }
};

int main () {
  std::cout << Solution().reformat("a0b1c2");

  return 0;
}