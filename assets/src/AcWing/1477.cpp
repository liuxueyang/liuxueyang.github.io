#include <cstdio>

using namespace std;
const int N = 110;
char s[N];
const char *e[10] {
  "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    };

int main() {
#ifdef _DEBUG
  freopen("1477.in", "r", stdin);
#endif
  scanf("%s", s);
  int x = 0;
  for (int i = 0; s[i]; ++i) {
    x += s[i] - '0';
  }

  int a[10], sz = 0;
  if (x == 0) {
    a[sz++] = 0;
  } else {
    while (x) {
      a[sz++] = x % 10;
      x /= 10;
    }
  }

  for (int i = sz - 1; i >= 0; --i) {
    printf("%s ", e[a[i]]);
  }
  puts("");

  return 0;
}
