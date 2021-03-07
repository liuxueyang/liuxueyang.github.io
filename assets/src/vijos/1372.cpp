#include <vector>
#include <string>
#include <iostream>

using namespace std;
using VI = vector<int>;

VI Add(VI& a, VI& b) {
  int n = a.size(), m = b.size(), t = 0;
  VI c;
  for (int i = 0; i < n || i < m; ++i) {
    if (i < n) t += a[i];
    if (i < m) t += b[i];
    c.push_back(t % 10);
    t /= 10;
  }
  if (t) c.push_back(t);
  return c;
}

bool cmp(VI& a, VI& b) {
  int n = a.size(), m = b.size();
  if (n != m) return n > m;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) return a[i] > b[i];
  }
  return true;
}

VI sub(VI& a, VI& b) {
  VI c;
  int t = 0, n = a.size(), m = b.size();
  for (int i = 0; i < n; ++i) {
    t = a[i] - t;
    if (i < m) { t -= b[i]; }
    c.push_back((t + 10) % 10);
    t = t < 0;
  }
  while (c.size() > 1 && !c.back()) c.pop_back();
  return c;
}

void print(VI& a) {
  int n = a.size();
  for (int i = n - 1, j = 0; i >= 0; --i, ++j) {
    if ((n - j) % 3 == 0) printf(",");
    printf("%d", a[i]);
  }
  puts("");
}

VI psub(VI& a, VI& b) {
  VI c;
  if (cmp(a, b)) {
    c = sub(a, b);
  } else {
    printf("-");
    c = sub(b, a);
  }
  return c;
}

int main() {
  #ifdef _DEBUG
  freopen("1372.in", "r", stdin);
  #endif

  string a, b;
  VI A, B, C;
  cin >> a >> b;
  int sa = 1, sb = 1, sza = a.size(), szb = b.size();
  for (int i = sza - 1; i >= 0; --i) {
    if (a[i] == '-') { sa = -1; continue; }
    A.push_back(a[i] - '0');
  }
  for (int i = szb - 1; i >= 0; --i) {
    if (b[i] == '-') { sb = -1; continue; }
    B.push_back(b[i] - '0');
  }

  if (sa == 1) {
    if (sb == 1) {
      C = psub(A, B);
    } else {
      C = Add(A, B);
    }
  } else {
    if (sb == 1) {
      printf("-");
      C = Add(B, A);
    } else {
      C = psub(B, A);
    }
  }
  print(C);

  return 0;
}
