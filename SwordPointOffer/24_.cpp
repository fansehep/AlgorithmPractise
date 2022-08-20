#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
  ListNode* reverseList(ListNode* head) {
    ListNode* t_node = head;
    stack<ListNode*> stk;
    while (t_node) {
      stk.push(t_node);
      t_node = t_node->next;
    }
    auto res = stk.top();
    auto tres = res;
    stk.pop();
    while (!stk.empty()) {
      tres->next = stk.top();
      stk.pop();
    }
    return res;
  }
};

int main() {
  return 0;
}