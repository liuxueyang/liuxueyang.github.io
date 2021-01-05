#include <iostream>
#include <cstring>

using namespace std;

const int N = 50, T = 20, V = 211;
int w[V][N], c[V][N], d[V], v, n, t, len[V];

int main() {
#ifdef DEBUG
  freopen("1272.in", "r", stdin);
#endif

  cin >> v >> n >> t;
  memset(len, 0, sizeof len);
  for (int i = 0; i < n; ++i) {
    int w1, c1, p;
    cin >> w1 >> c1 >> p;
    --p;
    int &tlen = len[p];
    w[p][tlen] = w1;
    c[p][tlen] = c1;
    tlen++;
  }
  memset(d, 0, sizeof d);
  for (int i = 0; i < t; ++i) {
    for (int v1 = v; v1 >= 0; --v1) {
      for (int j = 0; j < len[i]; ++j) {
        if (v1 >= w[i][j] && d[v1] < d[v1-w[i][j]] + c[i][j]) {
          d[v1] = d[v1-w[i][j]] + c[i][j];
        }
      }
    }
  }
  cout << d[v] << endl;

  return 0;
}
