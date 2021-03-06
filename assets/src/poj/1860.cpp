// 1860. Currency Exchange.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

const int N = 110 * 5;

struct Edge {
  int a, b;
  double r, c;
} edge[N];

int n, m, S, sz;
double V, dis[N];

void Init() {
  sz = 0;
}

bool bellman_ford() {
  for (int i = 1; i <= n; ++i) dis[i] = 0;
  dis[S] = V;

  for (int i = 1; i <= n; ++i) {
    bool flag = false;
    for (int j = 1; j <= sz; ++j) {
      Edge e = edge[j];         // NOTE: 啊！我竟然把下標寫錯了
      double tmp = (dis[e.a] - e.c) * e.r;
      if (tmp > dis[e.b]) {
        flag = true;
        dis[e.b] = tmp;
      }
    }
    if (i >= n && flag) {
      return true;
    }
  }
  return false;
}

int main()
{
#ifdef _DEBUG
  freopen("1860.in", "r", stdin);
#endif // _DEBUG

  scanf("%d%d%d%lf", &n, &m, &S, &V);

  Init();

  for (int i = 1; i <= m; ++i) {
    int a, b;
    double r1, c1, r2, c2;
    scanf("%d%d%lf%lf%lf%lf", &a, &b, &r1, &c1, &r2, &c2);
    edge[++sz].a = a; edge[sz].b = b;
    edge[sz].r = r1; edge[sz].c = c1;

    edge[++sz].a = b; edge[sz].b = a;
    edge[sz].r = r2; edge[sz].c = c2;
  }
  printf("%s\n", (bellman_ford() ? "YES" : "NO"));

  return 0;
}

/*
 * bellman ford 判斷是否含有正環
 循環 N 次，每次鬆弛所有的邊，如果第 N 次還有邊被鬆弛，那麼存在正環

 實現的時候有一處把下標寫錯了，調試了很久，以後不能深夜做題了，打錯一個字符調半天
 */
