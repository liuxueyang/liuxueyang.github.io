const int N = 1010;
int f[N][N];

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
      memset(f, 0, sizeof f);
      int n = arr.size(), res = 0;
      map<int, int> pos;
      for (int i = 0; i < n; ++i) pos[arr[i]] = i;

      for (int j = 0; j <= n - 2; ++j) {
        for (int i = j + 1; i <= n - 1; ++i) {
          int x = arr[i] - arr[j];
          if (pos.find(x) != pos.end()) {
            int k = pos[x];
            if (k < j) {
              f[i][j] = f[j][k] + 1;
              res = max(res, f[i][j]);
            }
          }
        }
      }

      res += 2;
      if (res <= 2) return 0;
      return res;
    }
};
