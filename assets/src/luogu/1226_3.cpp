#include <iostream>

using namespace std;
using ll = long long;

ll qmi(ll a, ll n, ll m) {
  if (a == 0 || m == 1) return 0;
  ll ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return ans;
}

int main(int argc, char *argv[])
{
  ll b, p, k;
  cin >> b >> p >> k;
  cout << b << '^' << p << " mod " << k <<
    "=" << qmi(b, p, k) << endl;
  return 0;
}
