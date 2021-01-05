#include <iostream>
#include <cstring>

using namespace std;

const int M = 233, N = 33;
int w[N], v[N], d[M], n, m;

int main() {
#ifdef DEBUG
  freopen("1268.in", "r", stdin);
#endif

  cin >> m >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> v[i];
  }

  memset(d, 0, sizeof d);
  for (int i = 0; i < n; ++i) {
    for (int j = w[i]; j <= m; ++j) {
      if (d[j] < d[j-w[i]] + v[i]) {
        d[j] = d[j-w[i]] + v[i];
      }
    }
  }

  cout << "max=" << d[m] << endl;

  return 0;
}
