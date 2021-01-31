#include <vector>
#include <cstring>

using namespace std;

const int N = 100010;
typedef unsigned long long ll;
ll p[N];

class Solution {
public:
  vector <bool> res;

  bool check(ll l1, ll r1, ll l2, ll r2) {
    if (r1 < l2 || r2 < l1) return false;
    return true;
  }

  vector<bool> canEatV1(vector<int> &a, vector<vector<int>> &b) {
    int len = a.size();

    memset(p, 0, sizeof p);

    p[0] = a[0];
    for (int i = 1; i < len; ++i) {
      p[i] = p[i-1] + a[i];
    }

    for (int i = 0; i < b.size(); ++i) {
      ll t = b[i][0], d = b[i][1], cp = b[i][2];
      ll l1, r1;

      if (t == 0) l1 = 0;
      else l1 = p[t-1];
      r1 = p[t] - 1;

      ll l2 = d, r2 = (d + 1) * cp - 1;
      res.push_back(check(l1, r1, l2, r2));
    }

    return res;
  }

  vector<bool> canEat(vector<int> &a, vector<vector<int>> &b) {
    int len = a.size();

    memset(p, 0, sizeof p);

    for (int i = 1; i <= len; ++i) {
      p[i] = p[i - 1] + a[i - 1];
    }

    for (int i = 0; i < b.size(); ++i) {
      ll t = b[i][0], d = b[i][1], cp = b[i][2];
      ll l1, r1, l2, r2;

      l1 = p[t] + 1;
      r1 = p[t + 1];

      l2 = d + 1;
      r2 = (d + 1) * cp;

      res.push_back(check(l1, r1, l2, r2));
    }

    return res;
  }
};
