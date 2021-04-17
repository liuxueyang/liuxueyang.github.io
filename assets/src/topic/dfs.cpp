#include <iostream>
#include <cstdio>

using namespace std;

const int N = 19;

int a[N] = {}, st[N] = {}, n, ans = 0;

void dfs(int k) {
  if (k == n + 1) {
    ans++;
    for (int i = 1; i <= n; ++i) {
      cout << a[i] << " ";
    }
    cout << endl;
    return;
  }

  for (int i = 1; i <= n; ++i) {
    if (!st[i]) {
      st[i] = 1;

      a[k] = i;
      dfs(k + 1);

      st[i] = 0;
    }
  }
}

int main() {
#ifdef _DEBUG
  freopen("dfs.in", "r", stdin);
#endif

  cin >> n;
  dfs(1);
  cout << ans << endl;

  return 0;
}
