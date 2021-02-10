#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1000010;
int n, m, ne[N];
char s[N], p[N];

int main() {
  scanf("%s%s", s + 1, p + 1);
  m = strlen(p + 1);
  n = strlen(s + 1);

  for (int i = 2, j = 0; i <= m; ++i) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) ++j;
    ne[i] = j;
  }

  int cnt = 0;
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) ++j;
    if (j == m) {
      j = ne[j];
      ++cnt;
    }
  }
  printf("%d\n", cnt);

  return 0;
}
