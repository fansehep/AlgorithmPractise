#include "leetcode.hpp"

class Solution {
  public:
  int isPrefixOfWord(string sentence, string searchWord) {
    const int sen_size = sentence.size();
    const int str_size = searchWord.size();
    int i = 0;
    int j = 0;
    int k = 0;
    int res = 1;
    for (; j < sen_size && k < str_size; ++j, ++k) {
      if (sentence[j] != searchWord[k]) {
        break;
      }
    }
    if (k == str_size) {
      return res;
    }
    for (; i < sen_size; ++i) {
      if (sentence[i] == ' ') {
        res++;
        j = i + 1;
        k = 0;
        for (; j < sen_size && k < str_size; ++k, ++j) {
          if (sentence[j] != searchWord[k]) {
            break;
          }
        }
        if (k == str_size) {
          return res;
        }
        i = j - 1;
      }
    }
    return -1;
  }
};