#include <bits/stdc++.h>

#include <limits>
using namespace std;

class Solution {
 public:
  int maxChunksToSorted(vector<int> &arr) {
    vector<int> v(arr.size(), INT_MAX);
    partial_sum(arr.crbegin(), arr.crend(), v.rbegin() + 1,
                [](int a, int b) { return min<int>(a, b); });
    return count_if(arr.cbegin(), arr.cend(),
                    [&v, e = 0, i = 1](int a) mutable {
                      return (e = max(e, a)) <= v[i++];
                    });
  }
};
