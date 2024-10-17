+++
title = '牛客小白月赛85 E 烙饼'
date = 2024-01-06T17:50:14+08:00
tags = [ "constructive algorithms", "math", "greedy" ]
categories = [ "牛客" ]
+++

- [烙饼](https://ac.nowcoder.com/acm/contest/72980/E)
- [tutorial](https://ac.nowcoder.com/discuss/1248427?type=101&order=0&pos=5&page=0&channel=-1&source_id=1)

设 $a_i$ 的和是 $sum$，每个机器的平均使用时间是 $avg = \lceil \frac{sum}{m} \rceil$，如果 $mx = max(a_i) > avg$，此时最优策略是让 $mx$ 一直在一台机器上，因为移动它不会让结果更好，此时的总时间就是 $mx$。如果 $mx \le avg$，此时总时间是 $avg$，从第一个机器开始考虑，因为 $a_i \le mx \le avg$，因此可以把 $a_i$ 放在第一个机器上，如果第一个机器还有剩余时间，把剩余的时间给 $a_{i + 1}$，然后对第二个机器，从时间 $0$ 开始，把 $a_{i + 1}$ 剩余的时间用完，此时可以保证 $a_{i + 1}$ 在两个机器上的时间是不会重合的，如果重合，这意味着 $a_{i + 1}$ 占用了前一个机器的后半段时间和后一个机器的前半段时间，并且这两段时间的和大于 $avg$，这和假设矛盾。因此每个 $a_i$ 最多产生两个记录。

接下来考虑为什么是取上整：$avg = \lceil \frac{sum}{m} \rceil$。如果 $sum \\% m \ne 0$，此时意味着存在一个 $a_i$ 还有剩余时间 $r_i, 1 \le r_i \lt m$，设 $avg_1 = \lfloor \frac{sum}{m} \rfloor$。一种方案是在最后一个机器上一直等 $a_i$ 完成，此时总时间是 $avg_1 + r_i$。另一种方案是把 $r_i$ 均摊到 $m$ 个机器上，也就是每个机器多用 $1$ 单位的时间，实际时间是 $avg_1 + 1$，并且总的可用时间多了 $m$，能够保证 $(avg_1 + 1) \cdot m \gt sum$，也就是一定可以完成所有的 $a_i$。

```cpp
// Date: Fri Jan  5 23:02:04 2024

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

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7, MOD1 = 998'244'353;
const ll INFL = 0x3f3f3f3f'3f3f3f3f;
const double eps = 1e-8;
const int dir[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

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
#define nemp(a) (!a.empty())
#define all(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define NL cout << '\n';

template <class T> bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

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

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

#ifdef _DEBUG
#define debug1(x) cout << #x " = " << x << endl;
#define debug2(x, y) cout << #x " = " << x << " " #y " = " << y << endl;
#define debug3(x, y, z)                                                        \
  cout << #x " = " << x << " " #y " = " << y << " " #z " = " << z << endl;
#define dbg(x...)                                                              \
  cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = [";    \
  _print(x);                                                                   \
  cerr << "\e[39m" << endl;
#else
#define debug1
#define debug2
#define debug3
#define dbg(x...)
#endif

const int N = 100100;
using PLL = pair<ll, ll>;

int n, m;
ll a[N];

void solve() {
  ll sum{}, mx{};

  For1(i, 1, n) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }

  ll tot = (sum + m - 1) / m;
  tot = max(tot, mx);

  vector<tuple<ll, ll, ll, ll>> res;

  ll cur{};
  int j = 1;

  For1(i, 1, n) {
    if (a[i] + cur <= tot) {
      res.pb({i, j, cur, cur + a[i]});
      cur += a[i];
      if (cur == tot) {
        cur = 0;
        ++j;
      }
    } else {
      res.pb({i, j, cur, tot});
      a[i] -= (tot - cur);
      ++j;
      res.pb({i, j, 0, a[i]});
      cur = a[i];
    }
  }

  cout << SZ(res) << '\n';
  for (auto &[id1, id2, l, r] : res) {
    cout << id1 << ' ' << id2 << ' ' << l << ' ' << r << '\n';
  }
}

int main(void) {
#ifdef _DEBUG
  freopen("e.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> n >> m) {
    solve();
  }

  return 0;
}
```
