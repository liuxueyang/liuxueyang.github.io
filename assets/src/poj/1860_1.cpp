#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;

struct W {
  W() {}
  W(double r, double c) : r(r), c(c) {}
  double r, c;
};

int st[N], n, cnt[N];
int e[N], ne[N], h[N], idx;
W w[N];
int S;
double V, dis[N];

void Init() {
  idx = 0;
  memset(h, -1, sizeof h);
  memset(st, 0, sizeof st);
  for (int i = 1; i <= n; ++i) {
    dis[i] = 0;
  }
  memset(cnt, 0, sizeof cnt);
}

void Add(int a, int b, W c) {
  e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa() {
  dis[S] = V;

  queue<int> q;
  q.push(S);
  st[S] = 1;

  while (!q.empty()) {
    int t = q.front();
    q.pop();
    st[t] = 0;

    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      W _w = w[i];
      double tmp = (dis[t] - _w.c) * _w.r;
      if (tmp > dis[j]) {
        dis[j] = tmp;
        cnt[j] = cnt[t] + 1;
        if (cnt[j] >= n) return true;
        if (!st[j])
          q.push(j);
      }
    }
  }
  return false;
}

int main() {
  #ifdef _DEBUG
  freopen("1860.in", "r", stdin);
  #endif

  int m;
  scanf("%d%d%d%lf", &n, &m, &S, &V);

  Init();

  for (int i = 1; i <= m; ++i) {
    int a, b;
    double r1, c1, r2, c2;
    scanf("%d%d%lf%lf%lf%lf", &a, &b, &r1, &c1, &r2, &c2);
    Add(a, b, W(r1, c1));
    Add(b, a, W(r2, c2));
  }
  printf("%s\n", (spfa() ? "YES" : "NO"));

  return 0;
}

/*
 * spfa 判斷正環
 AC
 */
