#include <iostream>
#include <cstdio>
#include <stack>
#include <cstdlib>

using namespace std;
const int N = 80009;
typedef long long LL;
LL h[N];
int main() {
  #ifdef DEBUG
  freopen("3250.in", "r", stdin);
  #endif
  
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) { scanf("%lld", h+i); }
    h[n] = LL(1e9+10);
  
    stack<int> s;
    while (!s.empty()) s.pop();
    LL sum = 0;
    s.push(0);
  
    for (int i = 1; i <= n; i++) {
      while (!s.empty() && h[s.top()] <= h[i]) {
        sum += (i - 1 - s.top());
        s.pop();
      }
      s.push(i);
    }
  
    printf("%lld\n", sum);
  }
  return 0;
}
