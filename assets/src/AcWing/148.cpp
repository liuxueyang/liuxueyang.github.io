#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 10010;
int h[N], sz, a[N];

void Down(int x) {
  int t = x, l = x * 2, r = x * 2 + 1;
  if (l <= sz && h[t] > h[l]) t = l;
  if (r <= sz && h[t] > h[r]) t = r;
  if (t == x) return;
  swap(h[t], h[x]);
  Down(t);
}

void Up(int x) {
  while (x / 2 && h[x / 2] > h[x]) {
    swap(h[x / 2], h[x]);
    x /= 2;
  }
}

void Push(int x) {
  h[++sz] = x;
  Up(sz);
}

int Pop() {
  int r = h[1];
  h[1] = h[sz--];
  Down(1);
  return r;
}

int main() {
  #ifdef _DEBUG
  freopen("148.in", "r", stdin);
  #endif

  int n;
  scanf("%d", &n);
  sz = n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", h + i + 1);
  }
  for (int i = n / 2; i; --i) Down(i);

  int res = 0;
  while (sz >= 2) {
    int x = Pop() + Pop();
    res += x;
    Push(x);
  }

  printf("%d\n", res);

  return 0;
}
