#include <bits/stdc++.h>

using namespace std;
using VI = vector<int>;
using PII = pair<int, int>;

int main() {
  #ifdef _DEBUG
  freopen("b.in", "r", stdin);
  #endif

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    char a[410][410];
    for (int i = 0; i < n; ++i) { cin >> a[i]; }

    vector<PII> pa;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == '*') {
          pa.push_back(PII(i, j));
        }
      }
    }

    int x1 = pa[0].first, y1 = pa[0].second,
      x2 = pa[1].first, y2 = pa[1].second;

    if (x1 == x2) {
      for (int i = 0; i < n; ++i) {
        if (i != x1) {
          a[i][y1] = a[i][y2] = '*';
          break;
        }
      }
    } else if (y1 == y2) {
      for (int j = 0; j < n; ++j) {
        if (j != y1) {
          a[x1][j] = a[x2][j] = '*';
          break;
        }
      }
    } else {
      a[x1][y2] = a[x2][y1] = '*';
    }

    ostream_iterator<char*> oi(cout, "\n");
    copy(a, a + n, oi);
  }

  return 0;
}
