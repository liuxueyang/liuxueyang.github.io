#include <iostream>
#include <cstdio>
#include <stack>
#include <cstdlib>

using namespace std;
const int N = 80009;
typedef long long LL;
LL h[N], stk[N];

int main() {
  #ifdef DEBUG
  freopen("3250.in", "r", stdin);
  #endif
  
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) { scanf("%lld", h+i); }
    h[n] = LL(1e9+10);

    int tt = 0;
    LL sum = 0;
    stk[++tt] = 0;
  
    for (int i = 1; i <= n; i++) {
      while (tt && h[stk[tt]] <= h[i]) {
        sum += (i - 1 - stk[tt]);
        --tt;
      }
      stk[++tt] = i;
    }
  
    printf("%lld\n", sum);
  }
  return 0;
}
