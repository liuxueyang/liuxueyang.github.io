#include <cstdio>

using namespace std;

int main() {
  #ifdef _DEBUG
  freopen("441.in", "r", stdin);
  #endif

  int l, r;
  scanf("%d%d", &l, &r);

  int res = 0;
  for (int i = l; i <= r; ++i) {
    for (int j = i; j; j /= 10) {
      res += j % 10 == 2;
    }
  }
  printf("%d\n", res);

  return 0;
}
