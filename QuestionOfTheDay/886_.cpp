#include "leetcode.hpp"

class Solution {
 public:
  bool dfs(int cur_node, int now_color, vector<int>& color,
           const vector<vector<int>>& g) {
    color[cur_node] = now_color;
    for (auto& next_node : g[cur_node]) {
      if (color[next_node] && color[next_node] == color[cur_node]) {
        return false;
      }
      if (!color[next_node] && !dfs(next_node, 3 ^ now_color, color, g)) {
        return false;
      }
    }
    return true;
  }
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<int> color(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (auto& p : dislikes) {
      g[p[0]].push_back(p[1]);
      g[p[1]].push_back(p[0]);
    }

    const int size = g.size();
    for (int i = 0; i < size; i++) {
      const int l_size = g[i].size();
      for (int j = 0; j < l_size; j++) {
        printf("%d ", g[i][j]);
      }
    }

    for (int i = 0; i <= n; ++i) {
      if (color[i] == 0 && !dfs(i, 1, color, g)) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  vector<vector<int>> nums = {{1, 2}, {2, 3}, {1, 3}};
  Solution().possibleBipartition(3, nums);
  return 0;
}