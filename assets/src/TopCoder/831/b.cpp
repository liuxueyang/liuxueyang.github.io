// Date: Wed Jun  8 19:22:59 2022

#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i, a, b) for (int i = int(a); i < int(b); ++i)
#define PER(i, a, b) for (int i = int(b) - 1; i >= int(a); --i)
#define REP1(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define PER1(i, a, b) for (int i = int(b); i >= int(a); --i)
#define REPE(i, j) for (int i = h[j]; i != -1; i = ne[i])

#define f1 first
#define f2 second
#define pb push_back
#define has(a, x) (a.find(x) != a.end())
#define nonempty(a) (!a.empty())
#define all(a) (a).begin(),(a).end()
#define SZ(a) int((a).size())

#ifdef _DEBUG
#define debug1(x) cout << #x" = " << x << endl;
#define debug2(x,y) cout << #x" = " << x << " "#y" = " << y << endl;
#define debug3(x,y,z) cout << #x" = " << x << " "#y" = " << y << " "#z" = " << z << endl;
#else
#define debug1
#define debug2
#define debug3
#endif

const int N = 30, M = N * 10;
int h[N], n, m, idx, st[N], g[N][N], dg[N], vis[N];
int e[M], ne[M];

void Init() {
  idx = 0;
  memset(st, 0, sizeof st);
  memset(h, -1, sizeof h);
  memset(g, 0, sizeof g);
  memset(dg, 0, sizeof dg);
  memset(vis, 0, sizeof vis);
}

void dfs(int x) {
  vis[x] = 1;
  REP(i, 0, n) {
    if (g[x][i] && !vis[i]) {
      dfs(i);
    }
  }
}

class LockedBoxes {
public:
	vector <int> openAll(int N, vector <int> box, vector <int> key) {
    n = N;
    Init();
    int len = SZ(box);
    REP(i, 0, len) {
      int s = box[i], t = key[i];
      if (s == t) continue;
      if (!g[s][t]) {
        g[s][t]++;
        dg[t]++;
      }
    }

    VI res;

    REP(i, 0, n) {
      if (!dg[i]) {
        res.pb(i);
        dfs(i);
      }
    }

    REP(i, 0, n) {
      if (!vis[i]) {
        res.pb(i);
        dfs(i);
      }
    }

    return res;
	}
};

