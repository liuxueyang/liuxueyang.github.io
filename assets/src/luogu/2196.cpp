#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 30;
int a[N][N], d[N], f[N], n, p[N];

void ppath(int start) {
  if (start == p[start]) printf("%d", start);
  else {
    ppath(p[start]);
    printf(" %d", start);
  }
}

int main() {
  #ifdef _DEBUG
  freopen("2196.in", "r", stdin);
  #endif

  scanf("%d", &n);
  int res = 0, start = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", f + i);
    d[i] = f[i];
    if (d[i] > res) {
      res = d[i];
      start = i;
    }
    p[i] = i;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (a[i][j]) {
	int tmp = d[i] + f[j];
	if (tmp > d[j]) {
	  d[j] = tmp;
	  p[j] = i;
	}
	if (res < d[j]) {
	  res = d[j];
	  start = j;
	}
      }
    }
  }
  ppath(start);
  printf("\n%d\n", res);
  
  return 0;
}
