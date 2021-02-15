#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;
int h[N], sz, n;

void Down(int x) {
  int t = x, l = x << 1, r = x * 2 + 1;
  if (l <= sz && h[t] < h[l]) t = l;
  if (r <= sz && h[t] < h[r]) t = r;
  if (t == x) return;
  swap(h[t], h[x]);
  Down(t);
}

void Up(int x) {
  while (x / 2 && h[x / 2] < h[x]) {
    swap(h[x / 2], h[x]);
    x >>= 1;
  }
}

void Pop() {
  if (sz == 0) {
    printf("empty\n"); return;
  }
  printf("%d\n", h[1]);
  h[1] = h[sz--];
  Down(1);
}

int main() {
  #ifdef _DEBUG
  freopen("300.in", "r", stdin);
  #endif

  scanf("%d", &n);
  sz = 0;
  while (n--) {
    char s[20];
    scanf("%s", s);
    if (strcmp(s, "push") == 0) {
      int x;
      scanf("%d", &x);
      h[++sz] = x;
      Up(sz);
    } else {
      Pop();
    }
  }

  return 0;
}
