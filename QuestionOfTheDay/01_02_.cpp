#include "leetcode.hpp"


class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        for (auto& iter : s1) {
            nums[iter - 'a']++;
        }
        for (auto& iter : s2) {
            nums[iter - 'a']--;
        }
        for (auto& iter : nums) {
            if (iter != 0) {
                return false;
            }
        }
        return true;
    }
    int nums[26];
};
