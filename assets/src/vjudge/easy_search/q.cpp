// Date: Wed Sep 22 16:19:31 2021

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

const int N = 20;
bool row[N], col[N];
int res, n, k;
char a[N][N];

void dfs(int r, int cur) {
  if (cur == k) {
    res++;
    return;
  }
  if (r >= n) return;

  bool mark = false;
  for (int i = 0; i < n; ++i) {
    if (a[r][i] == '#' && !col[i]) {
      col[i] = true;
      dfs(r + 1, cur + 1);
      col[i] = false;
      
      mark = true;
    }
  }

  if (mark) dfs(r + 1, cur);
}

int main(void)
{
#ifdef _DEBUG
  freopen("q.in", "r", stdin);
#endif
  std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  while (cin >> n >> k) {
    if (n + k == -2) break;
    
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    res = 0;
    memset(col, false, sizeof col);
    memset(row, false, sizeof row);
    dfs(0, 0);

    cout << res << "\n";
  }

  return 0;
}
