#include <bits/stdc++.h>

using namespace std;

int main() {
  #ifdef _DEBUG
  freopen("a.in", "r", stdin);
  #endif

  int t;
  cin >> t;
  while (t--) {
    int n;
    int a[110];

    cin >> n;

    map<int, int> m;
    int target;

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
      m[a[i]]++;
      if (m[a[i]] > 1) {
        target = a[i];
        break;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (target != a[i]) {
        cout << i + 1 << endl;
        break;
      }
    }
  }

  return 0;
}
