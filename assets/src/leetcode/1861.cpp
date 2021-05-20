// TODO:

class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; ++i) {
      int r = m;
      for (int j = m - 1; j >= 0; --j) {
        if (a[i][j] == '*') r = j;
      }
    }
  }
};
