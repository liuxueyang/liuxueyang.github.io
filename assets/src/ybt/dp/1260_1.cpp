#include <iostream>

using namespace std;

const int N = 1100;
int a[N], d[N], n = 0, p[N];

int main() {
  #ifdef DEBUG
  freopen("1260.in", "r", stdin);
  #endif

  n = 0;
  int tmp, res = 1;
  while ( cin >> tmp ) {
    d[n] = 1;
    p[n] = 0;
    a[n++] = tmp;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[i] <= a[j]) {
        tmp = d[j] + 1;
        if (tmp > d[i]) {
          d[i] = tmp;
          if (res < d[i]) {
            res = d[i];
          }
        }
      }
    }
  }

  if (n == 0) {
    cout << 0 << endl << 0 << endl;
    return 0;
  }

  int len = 1;
  p[0] = a[0];
  for (int i = 1; i < n; i++) {
    int pos = -1;
    for (int j = 0; j < len; j++) {
      if (p[j] >= a[i]) {
        if (pos == -1) {
          pos = j;
        } else {
          if (p[j] < p[pos]) {
            pos = j;
          }
        }
      }
    }
    if (pos == -1) {
      p[len++] = a[i];
    } else {
      p[pos] = a[i];
    }
  }
  cout << res << endl << len << endl;

  return 0;
}
