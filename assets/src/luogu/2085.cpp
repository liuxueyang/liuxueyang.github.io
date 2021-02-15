#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 10010;
int a[N], b[N], c[N], h[N], d[N], sz, n, m;

void Down(int x) {
  int t = x, l = x * 2, r = x * 2 + 1;
  if (l <= sz && h[t] < h[l]) t = l;
  if (r <= sz && h[t] < h[r]) t = r;
  if (t == x) return;
  swap(h[t], h[x]);
  Down(t);
}

void Up(int x) {
  while (x / 2 && h[x / 2] < h[x]) {
    swap(h[x], h[x / 2]);
    x /= 2;
  }
}

int Pop() {
  int r = h[1];
  h[1] = h[sz--];
  Down(1);
  return r;
}

int Push(int x) {
  if (sz < m) {
    h[++sz] = x;
    Up(sz);
    return 0;
  } else if (sz == m) {
    if (h[1] > x) {
      Pop();
      Push(x);
      return 0;
    }
  }
  return -1;
}

inline int fun(int i, int x) {
  return a[i] * x * x + b[i] * x + c[i];
}

int main() {
  #ifdef _DEBUG
  freopen("2085.in", "r", stdin);
  #endif

  sz = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", a + i, b + i, c + i);
    for (int j = 1; j <= m; ++j) {
      int tmp = fun(i, j);
      int t = Push(tmp);
      if (t == -1) break;
    }
  }

  int k = 0;
  while (sz) {
    d[++k] = Pop();
  }
  for (int i = k; i >= 1; --i) printf("%d ", d[i]);
  puts("");

  return 0;
}
