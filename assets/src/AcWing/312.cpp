#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 400, D = 50;
int a[N], b[10], n, m, d[D][D][D][D];

int main() {
#ifdef _DEBUG
  freopen("312.in", "r", stdin);
#endif

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    ++b[x];
  }

  d[0][0][0][0] = a[0];
  for (int A = 0; A <= b[1]; ++A) {
    for (int B = 0; B <= b[2]; ++B) {
      for (int C = 0; C <= b[3]; ++C) {
        for (int D = 0; D <= b[4]; ++D) {
          int s = a[A * 1 + B * 2 + C * 3 + D * 4];
          int &v = d[A][B][C][D];
          if (A)
            v = max(v, d[A - 1][B][C][D] + s);
          if (B)
            v = max(v, d[A][B - 1][C][D] + s);
          if (C)
            v = max(v, d[A][B][C - 1][D] + s);
          if (D)
            v = max(v, d[A][B][C][D - 1] + s);
        }
      }
    }
  }
  printf("%d\n", d[b[1]][b[2]][b[3]][b[4]]);

  return 0;
}
