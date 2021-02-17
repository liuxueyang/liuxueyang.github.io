#include <cstdio>

const int N = 100010;
int a[N];

int main() {
  #ifdef _DEBUG
  freopen("15.in", "r", stdin);
  #endif

  a[0] = a[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (a[i] == 0) {
      for (int j = i * 2; j <= N; j += i)
        a[j] = 1;
    }
  }

  int n;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    printf("%s\n", a[x] ? "NO" : "YES");
  }

  return 0;
}
