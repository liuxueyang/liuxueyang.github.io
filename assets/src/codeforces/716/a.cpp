#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

const int N = 110;
int a[N], n;

int main() {
  #ifdef _DEBUG
  freopen("a.in", "r", stdin);
  #endif

  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);

    bool flag = true;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      if (flag) {
        int y = sqrt(x);
        if (y * y != x) flag = false;
      }
    }
    printf("%s\n", flag ? "NO" : "YES");
  }

  return 0;
}
