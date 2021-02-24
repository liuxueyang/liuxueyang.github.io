#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

string dfs(stringstream& ss) {
  string res, X;
  int cnt = 0;
  char c;

  while (ss >> c) {
    if (c == '[') {
      ss >> cnt;
      X = dfs(ss);
      while (cnt--) res += X;
    } else if (c == ']') {
      return res;
    } else {
      res += c;
    }
  }

  return res;
}

int main() {
  #ifdef _DEBUG
  freopen("1928.in", "r", stdin);
  #endif

  string s;
  cin >> s;
  stringstream ss(s);
  cout << dfs(ss) << endl;

  return 0;
}
