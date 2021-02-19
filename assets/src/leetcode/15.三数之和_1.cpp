class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& a) {
    vector<vector<int>> res;
    if (a.size() == 0) return res;

    sort(a.begin(), a.end());

    int n = a.size();
    int prev = 0;
    bool flag = false;

    for (int i = 0; i < n; ++i) {
      if (flag && i && prev == a[i]) continue;
      prev = a[i];
      int l = i + 1, r = n - 1, target = -prev;

      flag = false;
      int prel;
      while (l < r) {
        while (l < r && a[l] + a[r] > target) --r;
        if (l < r && a[l] + a[r] == target) {
          res.push_back({prev, a[l], a[r]});
          flag = true;
          prel = a[l];
        }
        ++l;
        while (flag && l < r && prel == a[l]) ++l;
      }
    }

    return res;
  }
};
