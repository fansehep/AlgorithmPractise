#include <bits/stdc++.h>
using namespace std;

class OrderedStream {
 public:
  OrderedStream(int n) {
    nums.resize(n);
    ptr = 1;
    size = n;
  }
  vector<string> insert(int idkey, string value) {
    if (nums[ptr] != "") {
      vector<string> res;
      for (int i = ptr; i < size; i++) {
        if (nums[i] != "") {
          res.push_back(nums[i]);
        } else {
          ptr = i + 1;
          return res;
        }
      }
    }
    return {};
  }
  int size;
  vector<string> nums;
  int ptr;
};

int main() { return 0; }
