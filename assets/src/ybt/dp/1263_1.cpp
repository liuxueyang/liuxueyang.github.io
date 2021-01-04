#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5555;
struct Po {
  int a;
  int b;
};

struct Po p[N];
int n, d[N];

bool cmp (const Po& a, const Po& b) {
  return a.b < b.b;
}

int main() {
  #ifdef DEBUG
  freopen("1263.in", "r", stdin);
  #endif

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].a >> p[i].b;
    d[i] = 1;
  }
  sort(p, p + n, cmp);
  int res = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (p[j].a < p[i].a) {
        int tmp = d[j] + 1;
        if (tmp > d[i]) {
          d[i] = tmp;
          if (res < d[i]) {
            res = d[i];
          }
        }
      }
    }
  }
  cout << res << endl;

  return 0;
}
