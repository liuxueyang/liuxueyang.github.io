#include <cstdio>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;

int main(int argc, char *argv[])
{
  #ifdef _DEBUG
  freopen("1115.in", "r", stdin);
  #endif
  int n, res = -INF, a, b = res;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    if (b < 0) b = a;
    else b = b + a;
    res = max(res, b);
  }
  printf("%d\n", res);

  return 0;
}
