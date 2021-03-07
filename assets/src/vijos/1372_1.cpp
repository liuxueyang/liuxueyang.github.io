#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using VI = vector<int>;

VI Add(VI& a, VI& b) {
  VI c;
  int t = 0, n = a.size(), m = b.size();
  for (int i = 0; i < n || i < m; i++) {
    if (i < n) t += a[i];
    if (i < m) t += b[i];
    c.push_back(t % 10);
    t /= 10;
  }
  if (t) c.push_back(t);

  return c;
}

VI Sub(VI& a, VI& b) {
  VI c;
  int t = 0, n = a.size(), m = b.size();
  for (int i = 0; i < n; ++i) {
    t = a[i] - t;
    if (i < m) t -= b[i];
    c.push_back((t + 10) % 10);
    t = t < 0;
  }

  while (c.size() > 1 && !c.back()) c.pop_back();
  return c;
}

bool cmp(VI& a, VI& b) {
  int n = a.size(), m = b.size();
  if (n != m) return n > m;
  for (int i = 0; i < n; ++i)
    if (a[i] != b[i]) return a[i] > b[i];
  return true;
}

void print(VI& a) {
  int n = a.size();
  for (int i = n - 1, j = 0; i >= 0; --i, ++j) {
    if ((n - j) % 3 == 0 && j) printf(",");
    printf("%d", a[i]);
  }
  puts("");
}

void pSub(VI& a, VI& b) {
  VI c;
  if (cmp(a, b)) {
    c = Sub(a, b);
  } else {
    printf("-");
    c = Sub(b, a);
  }
  print(c);
}

int main() {
  #ifdef _DEBUG
  freopen("1372.in", "r", stdin);
  #endif

  string a, b;
  VI A, B, C;
  cin >> a >> b;
  int sa = 1, sb = 1;
  for (int i = a.size() - 1; i >= 0; --i)
    if (a[i] == '-') { sa = -1; break; }
    else A.push_back(a[i] - '0');
  for (int i = b.size() - 1; i >= 0; --i)
    if (b[i] == '-') { sb = -1; break; }
    else B.push_back(b[i] - '0');

  if (sa == 1) {
    if (sb == 1) {
      pSub(A, B);
    } else {
      C = Add(A, B);
      print(C);
    }
  } else {
    if (sb == 1) {
      printf("-");
      C = Add(A, B);
      print(C);
    } else {
      pSub(B, A);
    }
  }

  return 0;
}
