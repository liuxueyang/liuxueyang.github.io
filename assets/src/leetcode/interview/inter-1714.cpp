class Solution {
public:
  using VI = vector<int>;

  void Qsort(VI& a, int k, int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = a[(l + r) / 2];
    while (i < j) {
      while (a[++i] < x) ;
      while (a[--j] > x) ;
      if (i < j) swap(a[i], a[j]);
    }

    int le = j - l + 1;
    if (le >= k) Qsort(a, k, l, j);
    else Qsort(a, k - le, j + 1, r);
  }

  vector<int> smallestK(vector<int>& a, int k) {
    int n = a.size();
    Qsort(a, k, 0, n - 1);
    VI res;
    for (int i = 0; i < k; ++i) res.push_back(a[i]);
    return res;
  }
};
