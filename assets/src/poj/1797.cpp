#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> PII;

const int N = 2000010, INF = 0x3f3f3f3f;
int dis[N], w[N], st[N], n;
int e[N], ne[N], h[N], idx;

void Init() {
  memset(dis, 0, sizeof dis);
  memset(st, 0, sizeof st);
  memset(h, -1, sizeof h);
  idx = 0;
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
  dis[1] = INF;
  
  priority_queue<PII, vector<PII>, less<PII> > que;
  que.push(PII(INF, 1));
  while (!que.empty()) {
    PII t = que.top(); que.pop();
    int ver = t.second, base = t.first;
    if (st[ver]) continue; st[ver] = 1;
    for (int i = h[ver]; i != -1; i = ne[i]) {
      int j = e[i], tmp = min(base, w[i]);
      if (dis[j] != INF)
	dis[j] = max(dis[j], tmp);
      else dis[j] = tmp;
      // printf("j=%d, dis[j]=%d\n", j, dis[j]);
      que.push(PII(dis[j], j));
    }
  }
  return dis[n];
}

int main() {
  #ifdef _DEBUG
  freopen("1797.in", "r", stdin);
  #endif

  int T;
  scanf("%d", &T);
  for (int _i = 1; _i <= T; ++_i) {
    Init();
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      Add(a, b, c);
      Add(b, a, c);
    }
    printf("Scenario #%d:\n%d\n\n", _i, dijkstra());
  }
  
  return 0;
}

/*
求路径上最小边的最大值，修改 Dijkstra 实现
由于要求最大值，所以使用最大堆。
实现的时候的 Bug：
打模板的时候忘记了 push
调试很久，修改了一下输入样例才发现 bug
*/
