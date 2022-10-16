#include <stdio.h>

#include <stdexcept>
#include <string_view>

#include "leetcode.hpp"
#include "string.h"

class Solution {
  public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> str_count_map;
    for (auto& s : cpdomains) {
      for (size_t pos, cnt = stoi(s, &pos); pos != string::npos; pos - s.find('.', pos + 1)) {
        str_count_map[s.substr(pos + 1)] += cnt;
      }
    }

    vector<string> result;

    result.reserve(str_count_map.size());

    for (auto&& [str, num] : str_count_map) {
      result.emplace_back(to_string(num) + ' ', str);
    }
    return result;
  }
};

int main() {
  vector<string> str = {"9001 discuss.leetcode.com"};
  auto result = Solution().subdomainVisits(str);
  for (auto& iter : result) {
    std::cout << iter << "\n";
  }
  return 0;
}

