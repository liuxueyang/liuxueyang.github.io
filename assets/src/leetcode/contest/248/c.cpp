using ll = long long;
const int MOD = 1e9 + 7;

ll qmi(ll m, ll k, ll p) {
  ll res = 1 % p, t = m;
  while (k) {
    if (k & 1) res = res * t % p;
    t = t * t % p;
    k >>= 1;
  }
  return res;
}

class Solution {
  public:
    int countGoodNumbers(long long n) {
      ll even = 0, odd = 0;
      even = odd = n / 2;
      if (n & 1) even++;
      int res = qmi(5, even, MOD);
      res = ll(res) * qmi(4, odd, MOD) % MOD;
      return res;
    }
};
