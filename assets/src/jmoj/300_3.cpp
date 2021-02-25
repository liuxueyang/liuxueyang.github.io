#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

const int N = 100010;
int h[N], n, sz;

void Init() { sz = 0; memset(h, 0, sizeof h); }
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
    swap(h[x / 2], h[x]);
    x /= 2;
  }
}
void Push(int x) { h[++sz] = x; Up(sz); }
int Pop() {
  int r = h[1]; h[1] = h[sz--]; Down(1); return r;
}

int main() {
  #ifdef _DEBUG
  freopen("300.in", "r", stdin);
  #endif

  Init();
  scanf("%d", &n);
  while (n--) {
    string op; cin >> op;
    if (op == "push") {
      int x; cin >> x;
      Push(x);
    } else {
      if (!sz) cout << "empty\n";
      else cout << Pop() << endl;
    }
  }
  return 0;
}
