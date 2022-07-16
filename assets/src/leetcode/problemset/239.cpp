using VI = vector<int>;
const int N = 100010;
int q[N];

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& a, int k) {
    VI res;
    int cur = 0, n = a.size();
    int hh = 0, tt = -1;

    for (int j = 0; j < n; ++j) {
      while (hh <= tt && j - q[hh] >= k) {
        ++hh;
      }
      while (hh <= tt && a[q[tt]] <= a[j]) {
        --tt;
      }
      q[++tt] = j;

      if (j >= k - 1) res.push_back(a[q[hh]]);
    }
    return res;
  }
};
