+++
title = '蓝桥第2场小白入门赛 数学尖子生'
date = 2023-12-25T22:15:01+08:00
tags = [ "math" ]
categories = [ "蓝桥" ]
+++

- [数学尖子生](https://www.lanqiao.cn/problems/10013/learning/?contest_id=154)

先找到能够被 $1, 2, 3, \ldots, a - 1$ 整除的数字的个数，也就是求能够被 $lcm(1, 2, 3, \ldots, a - 1)$ 整除的数字的个数。同时要求不能被 $lcm(1, 2, 3, \ldots, a - 1, a)$ 整除，可以发现这两部分是子集的关系，直接相减即可。需要注意计算 $lcm$ 的时候，只需要计算 $lcm$ 在 $10^{16}$ 以内的，并且需要预处理。

```cpp
// Date: Sun Dec 24 16:11:22 2023

#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

const ull Pr = 131;

#define For(i, a, b) for (int i = int(a); i < int(b); ++i)
#define Rof(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define For1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define Rof1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define ForE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())

template <typename t> istream &operator>>(istream &in, vector<t> &vec) {
  for (t &x : vec)
    in >> x;
  return in;
}

template <typename t> ostream &operator<<(ostream &out, vector<t> &vec) {
  int n = SZ(vec);
  For(i, 0, n) {
    out << vec[i];
    if (i < n - 1)
      out << ' ';
  }
  return out;
}

#ifdef _DEBUG
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif

const int N = 10000'10;
ll b[N];
ll t, a, n;

ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }

ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int main(void) {
#ifdef _DEBUG
  freopen("e.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;

  int n1 = 10000'10;
  b[1] = 1;
  For1(i, 2, n1) {
    if (b[i - 1] > 10000'0000'0000'0000) {
      break;
    }
    b[i] = lcm(b[i - 1], i);
  }

  while (t--) {
    cin >> a >> n;

    if (a == 1) {
      cout << "0\n";
      continue;
    }

    ll k = b[a - 1], k1 = b[a], ans = 0;
    if (k && k1)
      ans = n / k - n / k1;
    cout << ans << '\n';
  }

  return 0;
}
```
