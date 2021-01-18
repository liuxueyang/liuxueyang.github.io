#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100009;
LL h[N], l[N], r[N];

int main() {
  #ifdef DEBUG
  freopen("2559.in", "r", stdin);
  #endif
  
  int n;
  while (~scanf("%d", &n) && n) {
    for (int i = 1; i <= n; ++i) scanf("%lld", h+i);
    h[n+1] = h[0] = -1;
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    LL res = 0;
    stack<int> sl, sr;
    while (!sl.empty()) sl.pop();
    while (!sr.empty()) sr.pop();
    
    sl.push(0);
    for (int i = 1; i <= n; ++i) {
      while (!sl.empty() && h[sl.top()] >= h[i]) {
        sl.pop();
      }
      l[i] = sl.top();
      sl.push(i);
    }
    
    sr.push(n+1);
    for (int i = n; i >= 1; --i) {
      while (!sr.empty() && h[sr.top()] >= h[i]) {
        sr.pop();
      }
      r[i] = sr.top();
      sr.push(i);
    }

    for (int i = 1; i <= n; ++i) {
      res = max(res, (r[i] - l[i] - 1) * h[i]);
    }
    
    printf("%lld\n", res);
  }
  
  return 0;
}
