class Solution {
public:
  int hIndex(vector<int>& a) {
    int n = a.size();

    int l = 0, r = n, mid;
    while (l < r) {
      mid = (l + r) >> 1;

      bool flag = false;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] >= mid) {
          cnt = n - 1 - i + 1;
          break;
        }
      }
    }
  }
};
