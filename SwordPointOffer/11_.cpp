#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minArray(vector<int>& numbers) {
    const int size = numbers.size();
    int i = 0;
    for (; i < size - 1; i++) {
      if (numbers[i] > numbers[i + 1]) {
        return numbers[i + 1];
      }
    }
    return 0;
  }
};
