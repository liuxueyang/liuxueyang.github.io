#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
using VI = vector<int>;

VI Add(VI& a, VI& b) {
  VI c;
  int t = 0, n = a.size(), m = b.size();
  for (int i = 0; i < n || i < m; ++i) {
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
    if (j && (n - j) % 3 == 0) printf(",");
    printf("%d", a[i]);
  }
  puts("");
}

VI pSub(VI& a, VI& b) {
  VI c;
  if (cmp(a, b)) {
    c = Sub(a, b);
  } else {
    printf("-");
    c = Sub(b, a);
  }
  print(c);
  return c;
}

int main() {
  #ifdef _DEBUG
  freopen("1372.in", "r", stdin);
  #endif

  string a, b;
  VI A, B, C;
  cin >> a >> b;

  int n = a.size(), m = b.size(), sa = 1, sb = 1;
  for (int i = n - 1; i >= 0; --i)
    if (a[i] != '-') A.push_back(a[i] - '0');
    else sa = -1;
  for (int i = m - 1; i >= 0; --i)
    if (b[i] != '-') B.push_back(b[i] - '0');
    else sb = -1;

  if (sa > 0) {
    if (sb > 0) {
      pSub(A, B);
    } else {
      print(C = Add(A, B));
    }
  } else {
    if (sb > 0) {
      printf("-");
      print(C = Add(A, B));
    } else {
      pSub(B, A);
    }
  }

  return 0;
}
