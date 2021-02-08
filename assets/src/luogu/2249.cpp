#include <cstdio>

using namespace std;

const int N = 1000010;
int n, m, q, a[N];

int main() {
  #ifdef _DEBUG
  freopen("2249.in", "r", stdin);
  #endif

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &q);
    int l = 0, r = n - 1, mid;
    while (l < r) {
      mid = l + r >> 1;
      if (a[mid] >= q) r = mid;
      else l = mid + 1;
    }
    if (a[r] == q) printf("%d ", r + 1);
    else printf("-1 ");
  }
  puts("");
  return 0;
}
