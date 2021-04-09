#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000010;
int n, m, ne[N];
char s[N], p[N];

int main() {
  #ifdef _DEBUG
  freopen("3375.in", "r", stdin);
  #endif

  scanf("%s%s", s + 1, p + 1);
  n = strlen(s + 1);
  m = strlen(p + 1);

  for (int i = 2, j = 0; i <= m; ++i) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) ++j;
    ne[i] = j;
  }

  for (int i = 1, j = 0; i <= n; ++i) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) ++j;
    if (j == m) {
      printf("%d\n", i - m + 1);
      j = ne[j];
    }
  }

  for (int i = 1; i <= m; ++i) printf("%d ", ne[i]);
  puts("");

  return 0;
}
