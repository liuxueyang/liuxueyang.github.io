#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010;
int a[N][N], l[N], r[N];

int main() {
  #ifdef DEBUG
  freopen("3494.in", "r", stdin);
  #endif

  int m, n;
  while (~scanf("%d%d", &m, &n)) {
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
    }
    for (int i = 2; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (a[i][j])
          a[i][j] += a[i-1][j];
      }
    }
    int res = 0;
    for (int i = 1; i <= m; ++i) {
      memset(l, 0, sizeof l);
      memset(r, 0, sizeof r);

      a[i][0] = a[i][n+1] = -1;
      stack<int> ls;
      while (!ls.empty()) ls.pop();
      ls.push(0);
      for (int j = 1; j <= n; ++j) {
        while (!ls.empty() && a[i][ls.top()] >= a[i][j]) {
          ls.pop();
        }
        l[j] = ls.top();
        ls.push(j);
      }

      a[i][0] = a[i][n+1] = -1;
      stack<int> rs;
      while (!rs.empty()) rs.pop();
      rs.push(n+1);
      for (int j = n; j >= 1; j--) {
        while (!rs.empty() && a[i][rs.top()] >= a[i][j]) {
          rs.pop();
        }
        r[j] = rs.top();
        rs.push(j);
      }

      int ires = 0;
      for (int j = 1; j <= n; ++j) {
        ires = max(ires, (r[j] - 1 - l[j]) * a[i][j]);
      }

      res = max(res, ires);
    }
    printf("%d\n", res);
  }

  return 0;
}
