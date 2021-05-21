class Solution {
public:
  int maxDistance(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size(), i = 0, j = 0, res = 0;
    for (; i < n; ++i) {
      while (j < m && j < i) ++j;
      while (j < m && b[j] >= a[i]) ++j;
      if (j && b[j - 1] >= a[i]) {
        res = max(res, j - 1 - i);
      }
    }
    return res;
  }
};
