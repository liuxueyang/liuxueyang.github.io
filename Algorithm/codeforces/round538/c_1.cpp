#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 1000500;
const int MOD = 1000000007;

void bad() {
  cout << "No" << endl;
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(false);

  long long n;
  long long b;
  cin >> n >> b;

  vector<pair<ll, int>> f;
  for (ll x = 2; x * x  <= b; ++x) {
    if (b % x == 0) {
      f.emplace_back(x, 0);
      while(b % x == 0) {
        f.back().second++;
        b /= x;
      }
    }
  }
  if (b > 1) {
    f.emplace_back(b, 1);
  }

  long long ans = numeric_limits<ll>::max();
  for (auto x : f) {
    ll m = n;
    long long res = 0;
    while (m > 0) {
      m /= x.first;
      res += m;
    }
    ans = min(ans, res / x.second);
  }
  cout << ans << endl;
  return 0;
}
