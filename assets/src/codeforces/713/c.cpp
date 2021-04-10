#include <bits/stdc++.h>

// TODO:

using namespace std;

int main() {
  #ifdef _DEBUG
  freopen("c.in", "r", stdin);
  #endif

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    string s;
    cin >> s;

    int n = a + b;

    bool flag = true;

    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') a--;
      else if (s[i] == '1') b--;
    }

    if (a < 0 || b < 0) flag = false;

    for (int i = 0, j = n - 1; i <= j && flag; ++i, --j) {
      if (s[i] == s[j]) {
        if (s[i] == '?') {
          if (i == j) {
            if (a > b) {
              a--;
              s[i] = '0';
            } else {
              b--;
              s[i] = '1';
            }
          } else {
            if (a > b) {
              a-=2;
              s[i] = s[j] = '0';
            } else {
              b-=2;
              s[i] = s[j] = '1';
            }
          }
        }
      } else {
        if (s[i] != '?' && s[j] != '?') {
          a = b = -1;
          flag = false;
          break;
        }
        else if (s[i] == '?') {
          if (s[j] == '0') a--;
          else b--;
          s[i] = s[j];
        } else if (s[j] == '?') {
          if (s[i] == '0') a--;
          else b--;
          s[j] = s[i];
        }
      }

      if (a < 0 || b < 0) {
        flag = false;
        break;
      }
    }

    if (!flag) {
      cout << -1 << endl;
    } else {
      cout << s << endl;
    }
  }

  return 0;
}
