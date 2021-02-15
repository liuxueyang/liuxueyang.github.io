#include <cstdio>

using namespace std;

const int N = 2000010;
int a[N];

int main() {
  #ifdef _DEBUG
  freopen("3156.in", "r", stdin);
  #endif

  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  while (m--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", a[x]);
  }
  return 0;
}
