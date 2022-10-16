#include "leetcode.hpp"

class Solution {
 public:
  const int N = 10000010;
  int numComponents(ListNode* head, vector<int>& nums) {
    unordered_set<int> numsSet;
    for (auto num : nums) {
      numsSet.insert(num);
    }
    bool inSet = false;
    int res = 0;
    while (head != nullptr) {
      if (numsSet.count(head->val)) {
        if (!inSet) {
          inSet = true;
          res++;
        }
      } else {
        inSet = false;
      }

      head = head->next;
    }

    return res;
  }
};