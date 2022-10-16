#include <queue>
#include "leetcode.hpp"

class Solution {
 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> res(k);
    sort(arr.begin(), arr.end());
    int i = 0;
    for (; i < k; i++) {
      res[i] = arr[i];
    }
    return res;
  }
  vector<int> getLeastNumbers2(vector<int>& arr, int k) {
    vector<int> res(k, 0);
    if (k == 0) {
      return res;
    }
    priority_queue<int> que;
    for (int i = 0; i < k; ++i) {
      que.push(arr[i]);
    }
    for (int i = k; i < arr.size(); ++i) {
      if (que.pop() > arr[i]) {
        
      }
    }
  }
};
