#include <iostream>
#include <cstring>

using namespace std;

const int N = 1111, M = 11111;
int a[N], n, m;
long long d[M];

int main() {
#ifdef DEBUG
  freopen("1273.in", "r", stdin);
#endif

  cin >> n >> m;
  memset(d, 0, sizeof d);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  d[0] = 1LL;
  for (int i = 0; i < n; ++i) {
    for (int j = a[i]; j <= m; ++j) {
      d[j] = d[j] + d[j-a[i]];
    }
  }
  cout << d[m] << endl;

  return 0;
}
