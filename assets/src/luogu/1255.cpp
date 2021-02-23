#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
using VI = vector<int>;

VI Add(VI& a, VI& b) {
  VI c;
  int t = 0;
  for (int i = 0; i < a.size() || i < b.size(); ++i) {
    if (i < a.size()) t += a[i];
    if (i < b.size()) t += b[i];
    c.push_back(t % 10); t /= 10;
  }
  if (t) c.push_back(t);
  return c;
}

int main() {
  #ifdef _DEBUG
  freopen("1255.in", "r", stdin);
  #endif

  int n;
  scanf("%d", &n);
  VI a {1}, b {2}, c;
  if (!n) { printf("0\n"); return 0; }
  else if (n == 1) { printf("1\n"); return 0; }
  else if (n == 2) { printf("2\n"); return 0; }
  for (int i = 0; i < n - 2; ++i) {
    c = Add(a, b);
    a = b; b = c;
  }
  for (int i = b.size() - 1; i >= 0; --i) printf("%d", b[i]);
  puts("");

  return 0;
}
