#include <cstdio>
#include <iostream>

using namespace std;

const int N = 15;
int n, res = 0, a[N], st[N], d1[N*2], d2[N*2];

void dfs(int k) {
  if (k == n + 1) {
    ++res;
    if (res <= 3) {
      for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
      }
      cout << endl;
    }

    return;
  }

  for (int i = 1; i <= n; ++i) {
    if (!st[i] && !d1[k - i + n] && !d2[k + i]) {
      st[i] = d1[k - i + n] = d2[k + i] = 1;

      a[k] = i;
      dfs(k + 1);

      st[i] = d1[k - i + n] = d2[k + i] = 0;
    }
  }
}

int main() {
  #ifdef _DEBUG
  freopen("1219.in", "r", stdin);
  #endif

  scanf("%d", &n);
  dfs(1);
  printf("%d\n", res);

  return 0;
}
