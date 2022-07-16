using VI = vector<int>;
using ll = long long;

// TODO:

class Solution {
public:
  VI a;
  int n, k;

  int check(int f) {
    int l = 0, r = n - 1, mid;
    while (l < r) {
      mid = (1 + l + r) / 2;
      if (a[mid] <= f) l = mid;
      else r = mid - 1;
    }
    if (a[l] > mid) return -1;
    return l;
  }

  int maxFrequency(vector<int>& _a, int _k) {
    a = _a;
    n = a.size();
    k = _k;
    sort(a.begin(), a.end());

    int l = 0, r = 1e5+10, mid, res = 0;

    while (l < r) {
      mid = (l + r) / 2;
      int pos = check(mid);
      if (pos == -1) {

      } else {
        int sum = 0, i = pos, cnt = 0;

      }
    }

    return res;
  }
};
