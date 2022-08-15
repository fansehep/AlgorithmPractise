#include <cstdint>
class MyCircularDeque {
public:
  const int SIZE = 1010;
  uint32_t nums[1010];
  uint32_t pre[1010];
  uint32_t next[1000];
  int curindex;
  int capacity;
  MyCircularDeque(int k) : capacity(k), curindex(0) {}

  bool insertFront(int value) {
    nums[cursize] = value;
    
  }

  bool insertLast(int value) {}

  bool deleteFront() {}

  bool deleteLast() {}

  int getFront() {}

  int getRear() {}

  bool isEmpty() {}

  bool isFull() {}
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */