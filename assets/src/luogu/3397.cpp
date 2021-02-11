#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
const int N = 1010;
int a[N][N], n;

void insert(int x1, int y1, int x2, int y2) {
  a[x1][y1] += 1;
  a[x2 + 1][y2 + 1] += 1;
  a[x1][y2 + 1] -= 1;
  a[x2 + 1][y1] -= 1;
}

int main() {
  #ifdef _DEBUG
  freopen("3397.in", "r", stdin);
  #endif
  int m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    insert(x1, y1, x2, y2);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
      printf("%d ", a[i][j]);
    }
    puts("");
  }
  
  return 0;
}
