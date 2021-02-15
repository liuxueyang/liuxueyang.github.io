#include <cstdio>

using namespace std;

const int N = 1010;
int a[N];

int main() {
  #ifdef _DEBUG
  freopen("1271.in", "r", stdin);
  #endif

  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  for (int i = 1; i <= n; ++i) {
    while (a[i]) { printf("%d ", i); a[i]--; }
  }
  puts("");

  return 0;
}
