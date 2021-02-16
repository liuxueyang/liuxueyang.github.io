#include <algorithm>
#include <cstdio>
#include <tuple>

using namespace std;
using PII = pair<int, int>;

const int N = 10010;
int a[N], b[N], c[N], sz, n, l[N];
PII h[N];

void Init() {
  sz = 0;
}

void Down(int x) {
  int t = x, l = x * 2, r = x * 2 + 1;
  if (l <= sz && h[t].first > h[l].first) t = l;
  if (r <= sz && h[t].first > h[r].first) t = r;
  if (t == x) return;
  swap(h[t], h[x]);
  Down(t);
}

void Up(int x) {
  while (x / 2 && h[x / 2].first > h[x].first) {
    swap(h[x / 2], h[x]);
    x /= 2;
  }
}

void Push(PII x) {
  h[++sz] = x;
  Up(sz);
}

PII Pop() {
  PII r = h[1];
  h[1] = h[sz--];
  Down(1);
  return r;
}

int fun(int i, int x) {
  return a[i] * x * x + b[i] * x + c[i];
}

int main() {
  #ifdef _DEBUG
  freopen("2085.in", "r", stdin);
  #endif

  int m;
  Init();

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", a + i, b + i, c + i);
    ++l[i];
    Push(PII(fun(i, l[i]), i));
  }

  while (m--) {
    PII r = Pop();
    printf("%d ", r.first);
    int i = r.second;
    ++l[i];
    Push(PII(fun(i, l[i]), i));
  }
  puts("");

  return 0;
}
