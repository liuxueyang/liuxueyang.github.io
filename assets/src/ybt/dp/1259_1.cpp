#include <iostream>

using namespace std;
const int N = 210;
int a[N], d[N], path[N], n;

void ppath(int pos) {
  if (pos == -1) return;
  if (path[pos] != -1) {
    ppath(path[pos]);
    cout << ' ' << a[pos];
  }
  else {
    cout << a[pos];
    return;
  }
}

int main() {
  #ifdef DEBUG
  freopen("1259.in", "r", stdin);
  #endif
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      d[i] = 1;
      path[i] = -1;
    }
    int res = 1, pos = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (a[j] <= a[i]) {
          int tmp = d[j] + 1;
          if (tmp > d[i]) {
            path[i] = j;
            d[i] = tmp;
            if (res < d[i]) {
              res = d[i];
              pos = i;
            }
          }
        }
      }
    }

    cout << "max=" << res << endl;
    ppath(pos);
    cout << endl;
  }

  return 0;
}
