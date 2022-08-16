#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  /*
   A B C E
   S F C S
   A D E E
   SEE
  */
  bool exist(const vector<vector<char>>& board, const string& word) {
    int h = board.size();
    int w = board[0].size();
    vector<vector<int>> visited(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        bool flag = check(board, visited, i, j, word, 0);
        if (flag) {
          return true;
        }
      }
    }
    return false;
  }
  bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j,
    string& s, int k) {
    if (board[i][j] != s[k]) {
      return false;
    } else if (k == s.length() - 1) {
      return true;
    }
    visited[i][j] = true;
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, }
  }
};

int main() {
  const vector<vector<char>>& test = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'F'}};
  std::cout << Solution().exist(test, "ABCD");
  return 0;
}
