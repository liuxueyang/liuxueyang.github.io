#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 100010, M = N, INF = 0x3f3f3f3f;

int n, m, dis[N], h[N], st[N];
int e[M], ne[M], w[M], idx;

void Init() {
  idx = 0;
  fill(h, h + n + 1, -1);
  fill(st, st + n + 1, 0);
  fill(dis, dis + n + 1, INF);
}

void Add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
  dis[1] = 0, st[1] = 1;
  queue<int> q({1});

  while (!q.empty()) {
    int t = q.front();
    q.pop();

    st[t] = 0;
    for (int i = h[t]; i != -1; i = ne[i]) {
      int j = e[i];
      if (dis[t] + w[i] < dis[j]) {
        dis[j] = dis[t] + w[i];
        if (!st[j]) {
          st[j] = 1;
          q.push(j);
        }
      }
    }
  }

  return dis[n];
}

int main() {
  #ifdef _DEBUG
  freopen("851.in", "r", stdin);
  #endif

  cin >> n >> m;
  Init();
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    Add(a, b, c);
  }

  auto res = spfa();
  cout << (res == INF ? "impossible" : to_string(res)) << endl;

  return 0;
}
