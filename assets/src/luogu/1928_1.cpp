#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

int pos, n;

string dfs(string s) {
  string res, X;
  int cnt = 0;

  while (pos < n) {
    if (s[pos] == '[') {
      cnt = 0;
      ++pos;
      while (pos < n && isdigit(s[pos])) {
        cnt = cnt * 10 + (s[pos] - '0');
        ++pos;
      }
      X = dfs(s);
      while (cnt--) res += X;
    } else if (s[pos] == ']') {
      return res;
    } else {
      res += s[pos];
    }
    ++pos;
  }

  return res;
}

int main() {
#ifdef _DEBUG
  freopen("1928.in", "r", stdin);
#endif

  string s;
  cin >> s;

  pos = 0;
  n = s.size();
  cout << dfs(s) << endl;

  return 0;
}
