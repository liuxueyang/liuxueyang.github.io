#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int n = s.size(), m = t.size();
  int idx = -1, len = n + 1;

  for (int i = 0, j = 0; i < n; ++i) {
    if (s[i] == t[j]) {
      ++j;
      if (j == m) {
        int j1 = j - 1, i1 = i;
        while (j1 >= 0 && i1 >= 0) {
          if (s[i1] == t[j1]) --j1;
          --i1;
        }
        int tmp = i - i1;
        if (tmp < len) {
          len = tmp;
          idx = i1 + 1;
        }
        j = 0;
      }
    }
  }

  if (idx == -1)
    cout << endl;
  else
    cout << s.substr(idx, len) << endl;

  return 0;
}
