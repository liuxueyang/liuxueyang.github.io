#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 10010, INF = 0x3f3f3f3f;
int n, dis[N], st[N], w[N], co[N], K, dis1[N];
int e[N], ne[N], h[N], idx;

void Add(int a, int b, int c, int d) {
  e[idx] = b, w[idx] = c, co[idx] = d,
    ne[idx] = h[a], h[a] = idx++;
}

struct ci {
  int dis, i, co;
  ci(int d, int i, int c) :dis(d), i(i), co(c) {}
  bool operator < (const ci & o) const {
    if (dis < o.dis) return true;
    else if (dis > o.dis) return false;
    else return co < o.co;
  }
  bool operator > (const ci & o ) const {
    return ! (*this < o);
  }
};

void Init() {
  memset(dis, INF, sizeof dis);
  memset(st, 0, sizeof st);
  memset(w, 0, sizeof w);
  memset(h, -1, sizeof h);
  memset(dis1, INF, sizeof dis1);
  idx = 0;
}

int dijkstra() {
  dis[1] = 0;
  dis1[1] = 0;

  priority_queue<ci, vector<ci>, greater<ci> > que;
  que.push(ci(0, 1, 0));

  while (!que.empty()) {
    ci t = que.top(); que.pop();
    int ver = t.i, base = t.dis, c = t.co;
    // if (st[ver]) continue;
    // st[ver] = 1;

    if (ver == n) {
      dis[n] = base;
      break;
    }
    
    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i], tmp = base + w[i],
	tmp1 = c + co[i];
      if (tmp1 <= K) {
	printf("%d %d %d\n", ver, j, tmp);
	dis[j] = min(dis[j], tmp);
	que.push(ci(j, tmp, tmp1));
      }
    }
  }

  return dis[n] == INF ? -1 : dis[n];
}

int main() {
  #ifdef _DEBUG
  freopen("1724.in", "r", stdin);
  #endif

  Init();
  int m;
  scanf("%d%d%d", &K, &n, &m);
  while (m--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    Add(a, b, c, d);
  }
  int res = dijkstra();
  printf("%d\n", res);
  
  return 0;
}

/*
  TODO
 */
