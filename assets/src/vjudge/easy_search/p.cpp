// Date: Wed Sep 22 16:10:36 2021

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;
const int dir[8][2] = {
  {0, 1}, {0, -1},
  {1, 0}, {-1, 0},
  {1, 1}, {1, -1},
  {-1, 1}, {-1, -1},
};

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int N = 30;
bool vis[N][N];
char a[N][N];
int res, n, m;

void dfs(int x, int y) {
  vis[x][y] = true;
  ++res;
  int x1, y1;
  for (int i = 0; i < 4; ++i) {
    x1 = x + dir[i][0], y1 = y + dir[i][1];
    if (x1 >= 0 && x1 < n &&
	y1 >= 0 && y1 < m &&
	!vis[x1][y1] &&
	a[x1][y1] == '.') {
      dfs(x1, y1);
    }
  }
}

int main(void)
{
#ifdef _DEBUG
  freopen("p.in", "r", stdin);
#endif

  while (~scanf("%d%d", &m, &n)) {
    if (n + m == 0) break;
    for (int i = 0; i < n; ++i) {
      scanf("%s", a[i]);
    }

    res = 0;
    memset(vis, false, sizeof vis);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	if (a[i][j] == '@') {
	  dfs(i, j);
	  break;
	}
      }
    }
    
    printf("%d\n", res);
  }
  
  return 0;
}
