// Date: Wed Sep 22 20:11:22 2021

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

const int N = 210;
int dis[N][N];
bool vis[N][N];
int n, m;
char a[N][N];

int main(void)
{
#ifdef _DEBUG
  freopen("r.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    memset(vis, false, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    queue<PII> que;
    int endx, endy;
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	if (a[i][j] == 'r') {
	  que.push(PII(i, j));
	  vis[i][j] = true;
	  dis[i][j] = 0;
	} else if (a[i][j] == 'a') {
	  endx = i, endy = j;
	}
      }
    }

    int res = INF;
    
    while (!que.empty()) {
      PII t = que.front(); que.pop();
      int x = t.first, y = t.second, x1, y1;
      vis[x][y] = false;
      
      for (int i = 0; i < 4; ++i) {
	x1 = x + dir[i][0]; y1 = y + dir[i][1];
	if (x1 >= 0 && x1 < n &&
	    y1 >= 0 && y1 < m &&
	    a[x1][y1] != '#') {
	  int tmp = dis[x][y] + 1;
	  if (a[x1][y1] == 'x') tmp++;
	  if (tmp < dis[x1][y1]) {
	    dis[x1][y1] = tmp;
	    if (!vis[x1][y1]) {
	      vis[x1][y1] = true;
	      que.push(PII(x1, y1));
	    }
	  }
	}
      }
    }

    res = dis[endx][endy];

    if (res == INF) cout << "Impossible\n";
    else cout << res << "\n";
  }

  return 0;
}
