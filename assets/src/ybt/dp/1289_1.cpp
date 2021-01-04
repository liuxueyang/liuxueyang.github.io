#include <iostream>
#include <cstring>

using namespace std;

const int N = 23;
int n, a[N], d[N], res, tmp;

int main() {
#ifdef DEBUG
  freopen("1289.in", "r", stdin);
#endif

  cin >> n;
  memset(d, 0, sizeof d);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    d[i] = 1;
  }
  res = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] >= a[i]) {
        tmp = d[j] + 1;
        if (tmp > d[i]) {
          d[i] = tmp;
          if (res < tmp) res = tmp;
        }
      }
    }
  }
  cout << res << endl;

  return 0;
}
