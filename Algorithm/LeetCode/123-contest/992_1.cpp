#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
int num[20005];
class Solution {
public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    auto calc = [&](int k) {
                  if (!k) return 0LL;
                  memset(num, 0, sizeof(num));
                  int j = 0;
                  int dis = 0;
                  int n = A.size();
                  ll tot = 0;
                  for (int i = 0; i < n; ++i) {
                    if (!num[A[i]]) ++dis;
                    ++num[A[i]];
                    while (dis > k) {
                      --num[A[j]];
                      if (!num[A[j]]) --dis;
                      ++j;
                    }
                    tot += i - j + 1;
                  }
                  return tot;
		};
    ll v = calc(K) - calc(K - 1);
    return v;
  }
};
