#include <algorithm>
#include <cstring>
#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int dis[N], g[N][N], st[N], n, res;

void Init() {
  memset(st, 0, sizeof st);
  memset(dis, INF, sizeof dis);
  memset(g, INF, sizeof g);
  res = 0;
}

void dijkstra() {
  dis[1] = 0;

  for (int i = 0; i < n; ++i) {
    int t = -1;
    for (int j = 1; j <= n; ++j)
      if (!st[j] && (t == -1 || dis[j] < dis[t]))
	t = j;
    st[t] = 1;
    for (int j = 1; j <= n; ++j) {
      if (g[t][j] != INF) {
	dis[j] = min(dis[j], dis[t] + g[t][j]);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (dis[i] != INF)
      res = max(res, dis[i]);
  }
}

int main() {
  #ifdef _DEBUG
  freopen("1502.in", "r", stdin);
  #endif

  Init();
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) {
    string s;
    for (int j = 1; j < i; ++j) {
      cin >> s;

      if (s == "x") continue;
      
      stringstream ss(s);
      int k;
      ss >> k;

      g[i][j] = g[j][i] = k;
    }
  }
  
  dijkstra();
  printf("%d\n", res);
  
  return 0;
}

/*
  求单源最短路，然后找出最大值

  题目看起来很长，我根本就没有读前面，直接阅读输入输出规则
  实现时候的 Bug：
  1. 又把初始化的时候的 sizeof 写错了
  2. 把 res 的初值写错了，要求最大值，应该初始化成最小
 */
