#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 233;
int a[N], d[N], p[N], g[N][N], n;

void ppath(int pos) {
  if (p[pos] == -1) {
    cout << pos+1;
    return;
  }
  ppath(p[pos]);
  cout << '-' << pos+1;
}

int main() {
#ifdef DEBUG
  freopen("1262.in", "r", stdin);
#endif

  memset(g, 0, sizeof g);
  memset(d, 0, sizeof d);
  cin >> n;
  int res = a[0], pos = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    d[i] = a[i];
    p[i] = -1;
    if (res < d[i]) {
      res = d[i];
      pos = i;
    }
  }
  int x, y;
  while (cin >> x >> y) {
    if (x + y == 0) break;
    g[x-1][y-1] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (g[j][i]) {
        int tmp = d[j] + a[i];
        if (tmp > d[i]) {
          d[i] = tmp;
          p[i] = j;
          if (res < d[i]) {
            res = d[i];
            pos = i;
          }
        }
      }
    }
  }
  ppath(pos);
  cout << endl;
  cout << res << endl;

  return 0;
}
