#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long LL;
const int N = 100009;
LL a[N], pre[N], l[N], r[N];

int main() {
  #ifdef DEBUG
  freopen("2796.in", "r", stdin);
  #endif

  int n;
  while (~scanf("%d", &n)) {
    memset(pre, 0, sizeof pre);
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a+i);
      pre[i] = a[i] + pre[i-1];
    }

    int left = -1, right = -1;
    LL res = -1;
    stack<int> ls, rs;
    while (!ls.empty()) ls.pop();
    while (!rs.empty()) rs.pop();
    a[0] = a[n+1] = -1;
    ls.push(0);
    rs.push(n+1);
    
    for (int i = 1; i <= n; ++i) {
      while (!ls.empty() && a[ls.top()] >= a[i]) {
        ls.pop();
      }
      l[i] = ls.top();
      ls.push(i);
    }
    for (int i = n; i >= 1; --i) {
      while (!rs.empty() && a[rs.top()] >= a[i]) {
        rs.pop();
      }
      r[i] = rs.top();
      rs.push(i);
    }
    for (int i = 1; i <= n; ++i) {
      LL ires = (pre[r[i] - 1] - pre[l[i]]) * a[i];
      if (ires > res) {
        res = ires;
        left = l[i] + 1;
        right = r[i] - 1;
      }
    }
    printf("%lld\n%d %d\n", res, left, right);
  }
  
  return 0;
}
