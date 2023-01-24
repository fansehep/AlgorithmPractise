#include "leetcode.hpp"

class Solution {
 public:
  //
  bool wordBreak(string s, vector<string>& wordDict) {
    auto word_dictset = unordered_set<string>();
    for (auto& word : wordDict) {
      word_dictset.insert(word);
    }
    const uint32_t size = wordDict.size() + 1;
    auto dp = vector<bool>(size + 1);
    dp[0] = true;
    int i = 1;
    int j = 0;
    for (; i <= s.size(); i++) {
      for (; j < i; ++j) {
        if (dp[j] &&
            word_dictset.find(s.substr(j, i - j)) != word_dictset.end()) {
          dp[j] = true;
          break;
        }
      }
    }
    return dp[s.size()];
  }
};
