#include <vector>
#include <map>
#include <cstring>

using namespace std;

const int N = 200010, P = 100000;
int n, h[N], e[N], ne[N], idx;

class Solution {
public:
  vector<int> res;

  void Init() {
    memset(h, -1, sizeof h);
    idx = 0;
  }

  void Add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
  }

  void dfs(int x, int p) {
    res.push_back(x - P);
    for (int i = h[x]; i != -1; i = ne[i]) {
      int j = e[i];
      if (j == p) continue;
      dfs(j, x);
    }
  }

  vector<int> restoreArray(vector<vector<int>> &ap) {
    int len = ap.size();
    if (!len) return res;

    map<int, int> m;
    Init();

    for (int i = 0; i < len; ++i) {
      int a = ap[i][0], b = ap[i][1];
      a += P;
      b += P;
      m[a]++;
      m[b]++;
      Add(a, b);
      Add(b, a);
    }

    int rot = -1;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
      if (it->second == 1) {
        rot = it->first;
        break;
      }
    }

    dfs(rot, -1);

    return res;
  }
};
