class Solution {
public:
  int totalFruit(vector<int>& a) {
    int n = a.size(), res = 0;
    map<int, int> m;

    for (int i = 0, j = 0; j < n; ++j) {
      m[a[j]]++;
      while (m.size() > 2) {
        int t = a[i++];
        m[t]--;
        if (m[t] == 0) m.erase(t);
      }
      res = max(res, j - i + 1);
    }
    return res;
  }
};
