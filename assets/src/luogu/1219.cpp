#include <cstdio>
#include <cstring>

using namespace std;

const int N = 15;
int col[N], row[N], d1[N*2], d2[N*2], n, ans;

void dfs(int x) {
  if (x == n) {
    ++ans;
    if (ans <= 3) {
      for (int i = 0; i < n; ++i) {
        printf("%d ", row[i]);
      }
      puts("");
    }
    return;
  }
  for (int j = 0; j < n; ++j) {
    if (!col[j] && !d1[x + j] && !d2[x - j + n]) {
      col[j] = d1[x + j] = d2[x - j + n] = 1;
      row[x] = j + 1;
      dfs(x + 1);
      col[j] = d1[x + j] = d2[x - j + n] = 0;
    }
  }
}

int main() {
  #ifdef _DEBUG
  freopen("1219.in", "r", stdin);
  #endif

  scanf("%d", &n);
  dfs(0);
  printf("%d\n", ans);

  return 0;
}
