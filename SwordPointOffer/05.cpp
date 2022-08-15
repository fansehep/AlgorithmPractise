#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
      const auto strsize = s.size();
      for (auto i = 0; i < strsize; i++) {
        if (s[i] == ' ') {
          s[i] = '%';
          s.insert(i+1, "20");
        }
      }
      return s;
    }
};

int main () {
  std::cout << Solution().replaceSpace("We are happy");


  return 0;
}