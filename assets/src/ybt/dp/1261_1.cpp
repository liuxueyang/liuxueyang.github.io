#include <iostream>

using namespace std;

const int N = 30;
const long long MAX = 0x3f3f3f3f;
int g[N][N], p[N], d[N], n;

void ppath(int pos) {
  if (p[pos] == -1) {
    cout << pos+1;
    return;
  } else {
    ppath(p[pos]);
    cout << ' ' << pos+1;
  }
}

int main() {
#ifdef DEBUG
  freopen("1261.in", "r", stdin);
#endif

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> g[i][j];
    }
    p[i] = -1;
    d[i] = MAX;
  }

  d[0] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (g[j][i] && d[j] != MAX) {
        int tmp = d[j] + g[j][i];
        if (tmp < d[i]) {
          d[i] = tmp;
          p[i] = j;
        }
      }
    }
  }
  cout << "minlong=" << d[n-1] << endl;
  ppath(n-1);
  cout << endl;

  return 0;
}
