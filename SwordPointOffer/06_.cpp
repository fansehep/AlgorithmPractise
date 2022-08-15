#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> nums;
        auto temp = head;
        while (temp != nullptr) {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }
};