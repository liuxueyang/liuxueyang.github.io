#include <cstdio>

using namespace std;

const int N = 1010;
int h[N], q[N], m, n;

int main() {
  #ifdef _DEBUG
  freopen("496.in", "r", stdin);
  #endif

  scanf("%d%d", &m, &n);
  int res = 0;
  int hh = 0, tt = -1;
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    if (!h[t]) {
      ++res;
      h[t] = 1;
      if (tt - hh + 1 >= m) {
        h[q[hh]] = 0;
        ++hh;
        q[++tt] = t;
      } else {
        q[++tt] = t;
      }
    }
  }
  printf("%d\n", res);

  return 0;
}
