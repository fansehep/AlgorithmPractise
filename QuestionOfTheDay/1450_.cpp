#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int sum = 0;
    const int size = startTime.size();
    for (int i = 0; i < size; i++) {
      if (startTime[i] >= queryTime && endTime[i] >= queryTime) {
        sum++;
      }
    }
    return sum;
  }
  int busyStudent_t(vector<int>& startTime, vector<int>& endTime, int queryTime) {

  }
};