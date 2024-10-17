+++
title = '蓝桥第2场小白入门赛 取余'
date = 2023-12-25T07:53:43+08:00
tags = [ "math" ]
categories = [ "蓝桥" ]
+++

- [取余](https://www.lanqiao.cn/problems/9989/learning/?contest_id=154)

对于给定的 $b_i$，考虑 $a_j \mod b_i$ 的结果，其中 $a_j \in [1, a]$，可以发现当 $a_j < b_i$ 时，$a_j \mod b_i = a_j$；当 $a_j > b_i$ 时，存在循环节，可以求出循环节的个数和两端的剩余部分。对这三部分分别求出有多少个值在范围 $[S, T]$ 中，这是可以 $O(1)$ 求出的。

```cpp
// Date: Sun Dec 24 15:30:01 2023

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

int a, b, s, t;

ll cal(int l, int r) {
  if (l > r)
    return 0;
  int left = max(l, s), right = min(r, t);
  if (left > right)
    return 0;
  return right - left + 1;
}

ll get(int x) {
  ll res = 0;

  if (a < x) {
    return cal(1, a);
  }
  res += cal(1, x - 1);

  int m = (a - (x - 1)) / x;
  res += m * cal(0, x - 1);

  int k = (a - (x - 1)) % x;
  if (k)
    res += cal(0, k - 1);

  return res;
}

int main(void) {
#ifdef _DEBUG
  freopen("d.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> a >> b >> s >> t) {
    ll res = 0;
    For1(i, 1, b) { res += get(i); }
    cout << res << '\n';
  }

  return 0;
}
```
