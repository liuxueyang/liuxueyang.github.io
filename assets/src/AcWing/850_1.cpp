#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 200010, INF = 0x3f3f3f3f;
int w[N], dis[N], st[N], n;
int e[N], ne[N], h[N], idx;
PII he[N];
int sz;

void Down(int x) {
  int t = x, l = x * 2, r = l + 1;
  if (l <= sz && he[l].first < he[t].first) t = l;
  if (r <= sz && he[r].first < he[t].first) t = r;
  if (t == x) return;
  swap(he[t], he[x]);
  Down(t);
}

void Up(int x) {
  while (x / 2 && he[x].first < he[x / 2].first) {
    swap(he[x], he[x / 2]);
    x /= 2;
  }
}

void Push(PII x) {
  he[++sz] = x;
  Up(sz);
}

PII Pop() {
  PII r = he[1];
  he[1] = he[sz--];
  Down(1);
  return r;
}

void Init() {
  memset(st, 0, sizeof st);
  memset(h, -1, sizeof h);
  idx = 0; sz = 0;
}
void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra() {
  memset(dis, INF, sizeof dis);
  dis[1] = 0;
  Push(PII(0, 1));

  while (sz) {
    PII t = Pop();
    int ver = t.second, base = t.first;
    if (st[ver]) continue;
    st[ver] = 1;

    for (int j = h[ver]; j != -1; j = ne[j]) {
      int u = e[j];
      if (base + w[j] < dis[u]) {
        dis[u] = base + w[j];
        Push(PII(dis[u], u));
      }
    }
  }
  return dis[n] == INF ? -1 : dis[n];
}

int main() {
#ifdef _DEBUG
  freopen("850.in", "r", stdin);
#endif

  int T;
  while (~scanf("%d%d", &n, &T)) {
    Init();

    while (T--) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      Add(a, b, c);
    }
    printf("%d\n", dijkstra());
  }

  return 0;
}
