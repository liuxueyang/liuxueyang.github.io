#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int N = 3000 * 25;
int a[N], b[N];

int main() {
  #ifdef _DEBUG
  freopen("1042.in", "r", stdin);
  #endif

  string s;
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  int idx = 0;

  while (cin >> s) {
    bool flag = false;

    for (auto &c : s) {
      if (c == 'W') a[idx++] = 1;
      else if (c == 'L') b[idx++] = 1;
      else if (c == 'E') {
        flag = true;
        break;
      }
    }

    if (flag) {
      while (cin >> s) ;
      break;
    }
  }

  int c[] = {11, 21}, l = 0, w = 0;
  for (int i = 0; i < 2; ++i) {
    l = w = 0;

    for (int j = 0; j < idx; ++j) {
      l += a[j];
      w += b[j];

      if (max(l, w) >= c[i] && abs(l - w) >= 2) {
        printf("%d:%d\n", l, w);
        w = l = 0;
      }
    }

    printf("%d:%d\n", l, w);
    // if (l || w) {
    // }

    if (i == 0)
      cout << endl;
  }

  return 0;
}
