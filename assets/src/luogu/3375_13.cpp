#include <iostream>
#include <string>
#include <cstring>
#include <iterator>

using namespace std;

const int N = 1000010;

char s[N], p[N];
int ne[N];

int main() {
  #ifdef _DEBUG
  freopen("3375.in", "r", stdin);
  #endif

  int n, m;

  cin >> (s + 1) >> (p + 1);
  n = strlen(s + 1);
  m = strlen(p + 1);

  for (int i = 2, j = 0; i <= m; ++i) {
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) ++j;
    ne[i] = j;
  }

  for (int i = 1, j = 0; i <= n; ++i) {
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) ++j;
    if (j == m) {
      cout << i - m + 1 << endl;
      j = ne[j];
    }
  }

  ostream_iterator<int> oi(cout, " ");
  copy(ne + 1, ne + m + 1, oi);
  cout << endl;

  return 0;
}
