#include "leetcode.h"
class CQueue {
public:
  stack<int> stk_1;
  stack<int> stk_2;
  CQueue () {}
  void appendTail (int value) {
    stk_1.push(value);
  }

  int deleteHead () {
    if (stk_1.empty()) {
      return -1;
    }
    stk_2.push(stk_1.top());
    stk_1.pop();
    
  }
};