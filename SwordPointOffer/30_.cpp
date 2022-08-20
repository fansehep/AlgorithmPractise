#include "leetcode.hpp"
class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() : size(1) { minvalue[0] = INT_MAX; }

  void push(int x) {
    stack[size++] = x;
    minvalue[size - 1] = ::min(x, minvalue[size - 2]);
  }

  void pop() { size--; }

  int top() { return stack[size]; }

  int min() { return minvalue[size]; }
  static const int N = 20010;
  uint32_t size;
  int stack[N];
  int minvalue[N];
};
// INT_MAX -2 0 -3 
//         -2 -2 -3
int main () {
  MinStack stk;
  stk.push(-2);
  stk.push(0);
  stk.push(-3);
  printf("min = %d\n", stk.min());
  stk.pop();
  stk.top();
  stk.min();
  return 0;
}
