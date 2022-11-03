#include "leetcode.hpp"

class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    const int n = nums.size();
    nums.insert(num);

    if (!n) {
      left = right = nums.begin();
    } else if (n & 1) {
      if (num < *left) {
        left--;
      } else {
        right++;
      }
    } else {
      if (num > *left && num < *right) {
        left++;
        right--;
      } else if (num >= *right) {
        left++;
      } else {
        right--;
        left = right;
      }
    }
  }

  double findMedian() {}

  multiset<int> nums;
  multiset<int>::iterator left;
  multiset<int>::iterator right;
};
