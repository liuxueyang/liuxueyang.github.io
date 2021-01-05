#include <iostream>
#include <cstring>

using namespace std;

const int M = 233, N = 33;
int n, m, d[M], c[N], v[N];

int main() {
#ifdef DEBUG
  freopen("1267.in", "r", stdin);
#endif

  cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c[i] >> v[i];
  }

  memset(d, 0, sizeof d);
  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= c[i]; --j) {
      if (d[j] < d[j-c[i]] + v[i]) {
        d[j] = d[j-c[i]] + v[i];
      }
    }
  }
  cout << d[m] << endl;

  return 0;
}
