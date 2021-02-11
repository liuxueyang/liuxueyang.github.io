#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 50010;
int a[N];

int main() {
  #ifdef _DEBUG
  freopen("2678.in", "r", stdin);
  #endif

  int L, N, M;
  scanf("%d%d%d", &L, &N, &M);
  for (int i = 1; i <= N; ++i) scanf("%d", a + i);
  int mid, l = 0, r = L;

  while (l < r) {
    mid = (l + r + 1) >> 1;
    int cnt = 0, prev = 0;
    bool flag = true;

    for (int i = 1; i <= N; ++i) {
      if (a[i] - prev < mid) ++cnt;
      else prev = a[i];
      if (cnt > M) { flag = false; break; }
    }

    if (flag) { l = mid; }
    else { r = mid - 1; }
  }
  printf("%d\n", l);

  return 0;
}
